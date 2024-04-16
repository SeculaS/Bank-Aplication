#include <stdio.h>
#include <string.h>
#include "banca.h"
#include <stdlib.h>

void creare_cont(struct ContBancar *cont,int argc,char*argv[]) {


    strcpy(cont->nume,argv[1]);
    strcpy(cont->prenume,argv[2]);

    printf("Introduceti IBAN-ul contului: ");
    scanf("%s", cont->iban);
    printf("Introduceti suma: ");
    scanf("%f", &cont->suma);


    FILE *f = fopen("conturi.txt", "r+");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }


    struct ContBancar cont_temp;
    bool cont_gasit = false;
    while (fscanf(f, "%s %s %s %f", cont_temp.nume, cont_temp.prenume, cont_temp.iban, &cont_temp.suma) != EOF) {

        if (strcmp(cont_temp.iban, cont->iban) == 0) {
            cont_temp.suma += cont->suma;
            fseek(f, -((long)sizeof(struct ContBancar)), SEEK_CUR);
            fprintf(f, "%s %s %s %.2f\n", cont_temp.nume, cont_temp.prenume, cont_temp.iban, cont_temp.suma);
            cont_gasit = true;
            break;
        }
    }


    if (!cont_gasit) {
        fprintf(f, "%s %s %s %.2f\n", cont->nume, cont->prenume, cont->iban, cont->suma);
    }


    fclose(f);
    system("cls");
    printf("Operatie finalizata cu succes!\n");
    printf("\n");

}

