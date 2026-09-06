FROM ubuntu:latest

RUN apt-get update && apt-get install -y socat

RUN useradd -m ctf
WORKDIR /home/ctf

COPY ./buffer /home/ctf
COPY ./flag.txt /home/ctf

#RUN gcc -o /home/ctf/shellcode /home/ctf/shellcode.c
RUN chmod 555 buffer

CMD socat TCP-LISTEN:1337,reuseaddr,fork EXEC:"/home/ctf/buffer",stderr,su=ctf