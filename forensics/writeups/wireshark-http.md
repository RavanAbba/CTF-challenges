# Wireshork — Writeup

**Flag:** `S2G{http_1s_cl3@rt3xt}`

## Approach

We sniffed some traffic from an "internal webhotel" and one request looks a
bit off. Open the capture, filter on `http`, and check the very first GET
request — the flag is sitting right there in the request line, because the
whole thing was sent over plain HTTP with no encryption at all. No decoding
tricks needed, just look.
