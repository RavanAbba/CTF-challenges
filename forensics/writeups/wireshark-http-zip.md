# Wireshork zip — Writeup

**Flag:** `S2G{Z1p_3ncyq1n_f2adl}`

## Approach

The capture shows a browser poking around a small web server. The first
request carries a password in the query string, which unlocks a directory
listing with two files: `flag.txt` and `secret.zip`.

Filter on `http` and follow the streams — the zip file is transferred in
full over the wire, so it can be carved back out with **File > Export
Objects > HTTP** in Wireshark. Once saved locally, unzip it using the
password spotted in the earlier request to get the flag.
