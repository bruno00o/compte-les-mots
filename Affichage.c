/**
 * @file Affichage.c
 * @author bruno00o
 * @brief Gestion de l'affichage pour le programme clm
 * @date 2022-03-21
 */

#include "Affichage.h"

void afficher_occs(ListeOcc liste) {
    while (liste->suivant != NULL) {
        printf("%s : %d\n", liste->mot, liste->occurence);
        liste = liste->suivant;
    }
}