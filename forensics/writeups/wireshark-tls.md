# Shork the wire - Writeup

**Flag:** `S2G{cn_flag_1n_c3rt339998878}`

## Approach

Filter the capture with `tls`, then find the packet carrying the TLS
certificate. In the packet details pane, expand:

```
Handshake Protocol: Certificate > Certificate
```

The flag is hiding in the certificate's Common Name (CN) field.
