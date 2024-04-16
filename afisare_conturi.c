#include <stdio.h>
#include <string.h>
#include "banca.h"

void afisare_conturi(struct ContBancar *cont) {
    system("cls");
    printf("Contul pentru %s %s este:\n", cont->nume, cont->prenume);
    printf("\n");
    printf("%-20s %-20s %-20s %-10s\n", "Nume", "Prenume", "IBAN", "Suma");
    printf("-----------------------------------------------------------------------------------\n");

    FILE *f = fopen("conturi.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }

    struct ContBancar cont_temp;
    bool cont_gasit = false;

    while (fscanf(f, "%s %s %s %f", cont_temp.nume, cont_temp.prenume, cont_temp.iban, &cont_temp.suma) != EOF) {
        if (strcmp(cont_temp.nume, cont->nume) == 0 && strcmp(cont_temp.prenume, cont->prenume) == 0) {
            printf("%-20s %-20s %-20s %-10.2f\n", cont_temp.nume, cont_temp.prenume, cont_temp.iban, cont_temp.suma);
            cont_gasit = true;
            break;
        }
    }

    if (!cont_gasit) {
        printf("Nu s-a gasit niciun cont pentru %s %s.\n", cont->nume, cont->prenume);
    }

    fclose(f);
}
