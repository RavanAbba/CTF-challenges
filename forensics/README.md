# Network Forensics Challenges

A set of network-forensics CTF challenges I designed and built, covering
packet analysis with Wireshark across a range of protocols and techniques.
Each challenge ships as a standalone capture file with a short prompt; full
solutions live separately so the challenges can still be attempted blind.

## Challenges

| Challenge | Difficulty | Technique |
|---|---|---|
| [Wireshork](challenges/wireshark-http) | Easy | Cleartext HTTP traffic analysis |
| [Wireshork zip](challenges/wireshark-http-zip) | Easy | HTTP object carving, password-protected zip |
| [Shork the wire](challenges/wireshark-tls) | Easy | TLS certificate inspection |
| [Wireshork (DNS)](challenges/wireshark-dns-exfiltration) | Easy | DNS exfiltration, chunked Base32 payload |
| [Chatlog](challenges/chatlog-wireshark) | Medium | TCP stream reassembly, single-byte XOR + Base64 |
| [Spaghetti](challenges/wireshark-base64) | Medium | Payload fragmented across many packets, reassembly + Base64 |
| [Sharks Revenge](challenges/wireshark-tls-keylog) | Medium | TLS decryption via a provided (pre)-master-secret keylog |

## Repo layout

```
challenges/   the files a participant gets: capture + a short prompt, no spoilers
writeups/     my solution for each challenge, including the flag
```

If you want to try a challenge yourself, open its folder under `challenges/`
and stop there — the matching file under `writeups/` gives away the answer.

## How these were built

Each challenge is generated from a small local setup (a plain HTTP server, a
TLS-enabled server run alongside a keylog, a scripted "chat" over a raw TCP
socket, etc.) captured live with `tcpdump`/Wireshark. The `capture.pcap(ng)`
in each folder is the raw traffic; where decryption is part of the puzzle
(TLS challenges), the necessary key material ships alongside it.

Metadata files (`meta.xml`) used for deploying these to a CTF platform are
kept out of this repo since they embed the flag values directly — see the
writeups instead for the answers.

## Author

Ravan Abbasov
