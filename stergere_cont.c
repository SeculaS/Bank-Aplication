#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "banca.h"

void stergere_cont(struct ContBancar *cont) {
    FILE *f = fopen("conturi.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (f == NULL || temp == NULL) {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }

    struct ContBancar cont_temp;
    bool cont_gasit = false;

    while (fscanf(f, "%s %s %s %f", cont_temp.nume, cont_temp.prenume, cont_temp.iban, &cont_temp.suma) != EOF) {
        if (strcmp(cont_temp.nume, cont->nume) == 0 && strcmp(cont_temp.prenume, cont->prenume) == 0) {
            cont_gasit = true;
        } else {
            fprintf(temp, "%s %s %s %.2f\n", cont_temp.nume, cont_temp.prenume, cont_temp.iban, cont_temp.suma);
        }
    }

    fclose(f);
    fclose(temp);

    if (remove("conturi.txt") != 0) {
        printf("Eroare la stergerea contului.\n");
        return;
    }

    if (rename("temp.txt", "conturi.txt") != 0) {
        printf("Eroare la redenumirea fisierului temporar.\n");
        return;
    }

    if (cont_gasit) {
            system("cls");
        printf("Contul pentru %s %s a fost sters.\n", cont->nume, cont->prenume);
    } else {
        printf("Nu s-a gasit niciun cont pentru %s %s.\n", cont->nume, cont->prenume);
    }
}

