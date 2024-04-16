#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "banca.h"


int main(int argc,char*argv[]) {
    system("color F0");
    struct ContBancar cont;
    bool are_cont = false;
    char optiune, buffer;



    strcpy(cont.nume , argv[1]);
    strcpy(cont.prenume , argv[2]);



    if (cont_existent(cont.nume, cont.prenume)) {
        printf("Contul a fost gasit.\n");
         printf("\n");
        are_cont = true;
    } else {
        printf("Contul nu a fost gasit.\n");
        printf("\n");
        printf("Doriti sa creati un cont nou? (Da/Nu): ");
        scanf(" %c", &optiune);
        system("cls");
        while ((buffer = getchar()) != '\n' && buffer != EOF);

        if (optiune == 'D' || optiune == 'd') {
            creare_cont(&cont,argc,argv);
            are_cont = true;
        } else {
            printf("La revedere.\n");
            return 0;
        }
    }

    do {
        printf("Ce operatiune doriti sa efectuati ?\n");
        printf("1. Adaugare bani in cont\n");
        printf("2. Extragere bani din cont\n");
        printf("3. Afisare informatii despre cont\n");
        printf("4. Stergere cont\n");
        printf("5. Iesire\n");
        printf("\n");
        printf("Alegeti optiunea: ");
        scanf(" %c", &optiune);
        while ((buffer = getchar()) != '\n' && buffer != EOF);

        switch (optiune) {
            case '1':
                if (are_cont) {
                    adaugare_bani(&cont);
                    system("cls");
                    printf("Suma a fost adaugata cu succes .\n");
                    printf("\n");
                } else {
                    printf("Nu puteti adauga bani fara un cont existent.\n");
                }
                break;
            case '2':
                if (are_cont) {
                    system("cls");
                    extragere_bani(&cont);
                    printf("Suma a fost extrasa cu succes .\n");
                    printf("\n");
                } else {
                    printf("Nu puteti extrage bani fara un cont existent.\n");
                }
                break;
            case '3':
                if (are_cont) {
                    afisare_conturi(&cont);
                    printf("\n");

                } else {
                    printf("Nu puteti afisa informatii fara un cont existent.\n");
                }
                break;
                case '4':
                if (are_cont) {
                    stergere_cont(&cont);
                    exit(0);
                } else {
                    printf("Nu puteti sterge un cont care nu exista.\n");
                }
                break;
            case '5':
                printf("La revedere.\n");
                exit(0);
            default:
                printf("Optiune invalida.\n");
        }
    } while(1);

    return 0;
}
