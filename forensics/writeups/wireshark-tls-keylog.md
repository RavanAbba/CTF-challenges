# Sharks Revenge - Writeup

**Flag:** `S2G{fb1_t0p_s3cr3333t911911911911}`

## Approach

This challenge requires participants to use the provided keylog file to
decrypt the traffic.

In Wireshark, go to **Edit > Preferences > Protocols > TLS** and set
"(Pre)-Master-Secret log filename" to `hard.keylog`.

This decrypts the session. Follow the TCP stream on the relevant packet and
the flag appears in the decrypted application data.
