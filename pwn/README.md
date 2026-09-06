# Pwn

Binary exploitation CTF challenges I designed and built - small, deliberately
vulnerable C programs served over a TCP socket via Docker, covering a few
classic stack-based memory-corruption bugs. Each challenge ships with its
binary and source so participants can read the code, find the bug, and write
their own exploit; full solutions with working `pwntools` scripts live
separately.

## Challenges

| Challenge | Difficulty | Technique |
|---|---|---|
| [Cool Program](challenges/ret2win-pwn) | Easy | Classic ret2win - stack buffer overflow overwrites the return address to jump into an unused `win()` function |
| [Easter Egg Hunt](challenges/egg-hunt) | Easy | Unbounded `gets()` overflow used to overwrite an adjacent stack variable and flip a win condition |
| [Personregister](challenges/overflow-pwn) | Medium | Buffer-size mismatch (`fgets` allowed to write more than the destination buffer holds) leading to a ret2win overwrite |

## Repo layout

```
challenges/   the files a participant gets: binary, source, Dockerfile, no spoilers
writeups/     my solution + working exploit script for each challenge, including the flag
```

If you want to try a challenge yourself, stay in `challenges/` and spin it up
locally:

```
cd challenges/<name>
docker compose up --build
nc localhost 1337
```

The matching file under `writeups/` gives away the vulnerability and the
flag.

## Notes

- Each challenge folder ships with a placeholder `flag.txt` so the Docker
  image builds and runs standalone. The real flags only appear in the
  writeups.
- `meta.xml` files used to deploy these to a CTF platform are kept out of
  this repo since they embed the real flag values directly.
- These binaries are intentionally vulnerable teaching examples compiled
  without stack canaries and without PIE, so the offsets and hardcoded
  addresses in the exploits are stable - don't reuse this code or these
  patterns anywhere real.
