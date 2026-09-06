# Wireshork (DNS) - Writeup

**Flag:** `S2G{dns_3xf1ldaw10kcmd9}`

## What was found

Amid normal ARP/IPv6/HTTPS noise, host `10.22.135.211` sent three DNS queries
to resolver `129.241.0.200` for a bogus domain, `leak.invalid`, over about
35 seconds:

- `01-kmzeo63enzzv6m3ymy.leak.invalid`
- `02-ywyzdbo4yta23dnvsd.leak.invalid`
- `03-s7i.leak.invalid`

The `NN-` prefix is a sequence number, indicating a payload chunked across
multiple DNS lookups.

## How it was decoded

The data segments use a Base32 alphabet (a–z, digits 2–7). Decoding each
chunk alone fails (misaligned padding), so concatenate them first, then
Base32-decode as one stream:

```
kmzeo63enzzv6m3ymy + ywyzdbo4yta23dnvsd + s7i
→ KMZEO63ENZZV6M3YMYYWYZDBO4YTA23DNVSDS7I=
→ S2G{dns_3xf1ldaw10kcmd9}
```
