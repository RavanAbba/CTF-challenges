#include <stdio.h>
#include <stdlib.h>

void win();

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