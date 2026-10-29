"""Call DuckStation's MCP server (https://github.com/sadnescity/duckstation) without an MCP client.

Sessions that started before the DuckStation plugin was installed don't have its mcp__ tools, and scripts never
do, so this talks to the server directly: JSON-RPC over Streamable HTTP on localhost:2346 (enable it with
[Debug] EnableMCPServer = true in DuckStation's settings.ini).

  python tools/duckstation.py tools                          list the 95 tools
  python tools/duckstation.py <tool> [json arguments]        call one, e.g.
  python tools/duckstation.py read_memory '{"address": "0x80018B88", "size": 32}'
  python tools/duckstation.py get_status

As a module: call("read_registers") returns the tool's result, parsed from JSON when it is JSON.
The CPU trace (tool "trace") writes %LOCALAPPDATA%/DuckStation/cpu_log.txt, about 80 bytes per instruction.
"""
import json
import sys
import urllib.request

URL = "http://localhost:2346/mcp"
_session = None


def _post(body, sid=None):
    req = urllib.request.Request(URL, data=json.dumps(body).encode(), method="POST", headers={
        "Content-Type": "application/json", "Accept": "application/json, text/event-stream",
        **({"MCP-Session-Id": sid} if sid else {})})
    with urllib.request.urlopen(req, timeout=120) as r:
        text = r.read().decode()
        sid = r.headers.get("MCP-Session-Id", sid)
    if text.startswith("event:") or text.startswith("data:"):  # an SSE-framed reply
        text = next(l[5:] for l in text.splitlines() if l.startswith("data:"))
    return (json.loads(text) if text.strip() else None), sid


def _sid():
    global _session
    if _session is None:
        _, _session = _post({"jsonrpc": "2.0", "id": 1, "method": "initialize", "params": {
            "protocolVersion": "2025-03-26", "capabilities": {}, "clientInfo": {"name": "koudelka", "version": "1"}}})
        _post({"jsonrpc": "2.0", "method": "notifications/initialized"}, _session)
    return _session


def rpc(method, params=None):
    reply, _ = _post({"jsonrpc": "2.0", "id": 2, "method": method, "params": params or {}}, _sid())
    if "error" in reply:
        raise RuntimeError(reply["error"])
    return reply["result"]


def call(tool, **arguments):
    res = rpc("tools/call", {"name": tool, "arguments": arguments})
    text = "".join(c.get("text", "") for c in res.get("content", []))
    if res.get("isError"):
        raise RuntimeError(f"{tool}: {text}")
    try:
        return json.loads(text)
    except ValueError:
        return text


def main():
    if len(sys.argv) < 2 or sys.argv[1] == "tools":
        for t in rpc("tools/list")["tools"]:
            print(f"{t['name']:28} {t.get('description', '')[:100]}")
        return
    out = call(sys.argv[1], **(json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}))
    print(json.dumps(out, indent=2) if not isinstance(out, str) else out)


if __name__ == "__main__":
    main()
