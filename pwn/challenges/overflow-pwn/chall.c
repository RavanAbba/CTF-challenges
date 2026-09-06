#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 80

struct Person {
    char navn[STRLEN];
    int alder;
};

struct Person* gPersoner[STRLEN];
int gAntallPersoner = 0;

void leggTilPerson();
void slettPerson();
void hemmeligMeny();
void skrivFlagg();

int main(void) {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    char kommando[8];

    puts("=== Person-register v1.0 ===");
    puts("Kommandoer:");
    puts("  L - legg til person");
    puts("  S - slett siste person");
    puts("  H - hjelp / admin-meny");
    puts("  Q - avslutt");

    while (1) {
        printf("\n> ");

        if (!fgets(kommando, sizeof(kommando), stdin)) {
            puts("Input-feil, avslutter.");
            break;
        }

        switch (kommando[0]) {
            case 'L':
                leggTilPerson();
                break;
            case 'S':
                slettPerson();
                break;
            case 'H':
                hemmeligMeny();
                break;
            case 'Q':
                puts("Avslutter programmet.");
                return 0;
            default:
                puts("Ukjent kommando.");
                break;
        }
    }

    return 0;
}

void leggTilPerson() {
    if (gAntallPersoner >= STRLEN) {
        puts("Kan ikke lagre flere personer.");
        return;
    }

    struct Person* person = malloc(sizeof(struct Person));
    if (!person) {
        puts("Klarte ikke å allokere minne.");
        exit(1);
    }

    gPersoner[gAntallPersoner++] = person;

    printf("Navnet på personen som du vil legge til: ");
    if (!fgets(person->navn, STRLEN, stdin)) {
        puts("Feil ved lesing av navn.");
        return;
    }


    person->navn[strcspn(person->navn, "\n")] = '\0';

    printf("Alderen til personen som du vil legge til: ");
    if (scanf(" %d", &person->alder) != 1) {
        puts("Ugyldig alder.");

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        return;
    }


    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("La til: %s (%d år)\n", person->navn, person->alder);
}

void slettPerson() {
    if (gAntallPersoner <= 0) {
        puts("Ingen personer å slette.");
        return;
    }

    free(gPersoner[--gAntallPersoner]);
    puts("Slettet sist registrerte person.");
}


void hemmeligMeny() {
    char adminCmd[16];

    puts("\n=== Admin-meny ===");
    printf("Skriv admin-kommando: ");

 
    fgets(adminCmd, STRLEN, stdin);  

    printf("Ugyldig admin-kommando: %s\n", adminCmd);
}


void skrivFlagg() {
    system("cat flag.txt");
    exit(0);
}
