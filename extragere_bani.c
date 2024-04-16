#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banca.h"

void extragere_bani(struct ContBancar *cont) {
    float suma_extrasa;
    printf("Introduceti suma de bani pe care doriti sa o extrageti: ");
    scanf("%f", &suma_extrasa);
    cont->suma -= suma_extrasa;

    FILE *f = fopen("conturi.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }


    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Eroare la deschiderea fisierului temporar.\n");
        fclose(f);
        return;
    }

    struct ContBancar temp_cont;


    while (fscanf(f, "%s %s %s %f", temp_cont.nume, temp_cont.prenume, temp_cont.iban, &temp_cont.suma) != EOF) {
        if (strcmp(cont->nume, temp_cont.nume) == 0 && strcmp(cont->prenume, temp_cont.prenume) == 0) {
            temp_cont.suma -= suma_extrasa;
        }
        fprintf(temp, "%s %s %s %.2f\n", temp_cont.nume, temp_cont.prenume, temp_cont.iban, temp_cont.suma);
    }


    fclose(f);
    fclose(temp);


    remove("conturi.txt");


    rename("temp.txt", "conturi.txt");
    system("cls");

}
