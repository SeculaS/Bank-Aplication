#ifndef BANCA_H
#define BANCA_H
#include <stdbool.h>


struct ContBancar {
    char nume[30];
    char prenume[30];
    char iban[30];
    float suma;
};

// Funcția pentru crearea unui cont bancar
void creare_cont(struct ContBancar *cont,int argc,char*argv[]);

// Funcția pentru adăugarea bani în cont
void adaugare_bani(struct ContBancar *cont);

// Funcția pentru afișarea informațiilor despre cont
void afisare_conturi(struct ContBancar *cont);

// Funcția pentru a verifica dacă un cont există deja în fișierul text
bool cont_existent(const char *nume, const char *prenume);

// Functia pentru a extrage bani din cont
void extragere_bani(struct ContBancar *cont);

//Functia pentru a sterge datele din fisierul text
void stergere_cont(struct ContBancar *cont);

#endif
