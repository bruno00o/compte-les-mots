/**
 * @file Chaine.c
 * @author bruno00o
 * @brief Fonctions de comparaisons des chaines de caractères
 * @date 2022-03-15
 */

#include "Chaine.h"

int chaine_egales(char* chaine1, char* chaine2) {
    int i;
    if (chaine1 == NULL || chaine2 == NULL) {
        return 0;
    }
    if (strlen(chaine1) != strlen(chaine2))
        return 0;
    for (i = 0; i < strlen(chaine1); i++) {
        if (chaine1[i] != chaine2[i])
            return 0;
    }
    return 1;
}

int compare_chaines(char* chaine1, char* chaine2) {
    int min;
    int i;
    if (chaine_egales(chaine1, chaine2)) {
        return 1;
    }
    min = MIN(strlen(chaine1), strlen(chaine2));
    for (i = 0; i < min; i++) {
        if (chaine1[i] > chaine2[i]) {
            return 0;
        }
        else if (chaine1[i] < chaine2[i]) {
            return 1;
        }
    }
    return 1;
}