#include <stdio.h>
#include <string.h>
#include "banca.h"

bool cont_existent(const char *nume, const char *prenume) {
    FILE *f = fopen("conturi.txt", "r");
    if (f != NULL) {
        struct ContBancar temp_cont;
        while (fscanf(f, "%s %s %s %f", temp_cont.nume, temp_cont.prenume, temp_cont.iban, &temp_cont.suma) != EOF) {
            if (strcmp(nume, temp_cont.nume) == 0 && strcmp(prenume, temp_cont.prenume) == 0) {
                fclose(f);
                return true;
            }
        }
        fclose(f);
    }
    return false;
}
