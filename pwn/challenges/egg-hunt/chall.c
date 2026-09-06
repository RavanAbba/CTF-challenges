#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

extern char *gets(char *);

void win() {
    char buf[64];
    FILE *f = fopen("flag.txt", "r");
    if (!f) {
        puts("flag.txt not found!");
        return;
    }
    fgets(buf, sizeof(buf), f);
    fclose(f);
    printf("The Easter Bunny rewards you! %s\n", buf);
}

int main() {
    char basket[32];
    int eggs = 0;

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin,  NULL, _IONBF, 0);

    puts("=== Easter Egg Hunt ===");
    puts("The Easter Bunny hid a secret egg. Can you find it?");
    printf("Enter your name, egg hunter: ");
    gets(basket);

    if (eggs == 0xdeadbeef) {
        win();
    } else {
        printf("Hello, %s! No golden egg for you. (eggs=0x%08x)\n", basket, (unsigned int)eggs);
    }
    return 0;
}
