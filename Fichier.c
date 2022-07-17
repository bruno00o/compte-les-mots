/**
 * @file Fichier.c
 * @author bruno00o
 * @brief Gestion des fichiers
 * @date 2022-03-15
 */

#include "Fichier.h"

FILE* ouvrir_fichier(const char* nomfichier) {
    FILE* fichier = NULL;
    fichier = fopen(nomfichier, "r");
    return fichier;
}

void fermer_fichier(FILE* nomfichier) {
    fclose(nomfichier);
}

