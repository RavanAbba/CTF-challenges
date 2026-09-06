# Chatlog - Writeup

**Flag:** `S2G{tcp_stream_xor_base64_ftw}`

## Approach

Open the capture and right-click the first packet sent by the client, then
**Follow > TCP Stream**. Set the direction filter to show only client-to-server
traffic and save that stream as a raw binary file (`stream_raw.bin`).

The payload is base64 wrapped in a single-byte XOR. Brute-forcing all 256 XOR
keys and checking which one produces valid base64 finds it quickly:

```python
import base64

data = open("stream_raw.bin", "rb").read()

for key in range(256):
    candidate = bytes(byte ^ key for byte in data)
    try:
        decoded = base64.b64decode(candidate, validate=True).decode()
        print("Key:", key, "->", decoded)
        break
    except Exception:
        pass
```

Running it recovers the flag.
