/**
 * @file Tri.c
 * @author bruno00o
 * @brief Gestion des tris
 * @date 2022-03-15
 */

#include "Tri.h"

void inverse_mots(Occ* mot_1, Occ* mot_2) {
    int occ_tmp;
    char* mot_tmp = mot_1->mot;
    occ_tmp = mot_1->occurence;
    mot_1->mot = mot_2->mot;
    mot_1->occurence = mot_2->occurence;
    mot_2->mot = mot_tmp;
    mot_2->occurence = occ_tmp;
}

ListeOcc tri_lexico(ListeOcc liste) {
    int inverse;
    Occ* debut;
    Occ* fin = NULL;
    if (liste == NULL) {
        return NULL;
    }
    do {
        inverse = 0;
        debut = liste;
        while (debut->suivant != fin) {
            if (debut->suivant->mot != NULL) {
                if (!compare_chaines(debut->mot, debut->suivant->mot)) {
                    inverse_mots(debut, debut->suivant);
                    inverse = 1;
                }
            }
            debut = debut->suivant;
        }
        fin = debut;
    } while (inverse);
    return liste;
}

ListeOcc tri_occurences(ListeOcc liste) {
    int inverse;
    Occ* debut;
    Occ* fin = NULL;
    if (liste == NULL) {
        return NULL;
    }
    do {
        inverse = 0;
        debut = liste;
        while (debut->suivant != fin) {
            if (debut->occurence < debut->suivant->occurence) {
                inverse_mots(debut, debut->suivant);
                inverse = 1;
            }
            else if (debut->occurence == debut->suivant->occurence) {
                if (!compare_chaines(debut->mot, debut->suivant->mot)) {
                    inverse_mots(debut, debut->suivant);
                    inverse = 1;
                }
            }
            debut = debut->suivant;
        }
        fin = debut;
    } while (inverse);
    return liste;
}