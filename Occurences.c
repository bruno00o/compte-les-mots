/**
 * @file Occurences.c
 * @author bruno00o
 * @brief Gestion des listes d'occurrences
 * @date 2022-03-15
 */

#include "Occurences.h"

Occ* alloue_occ(char* mot) {
    Occ* nouveau = malloc(sizeof(Occ));
    if (nouveau != NULL) {
        nouveau->mot = malloc((strlen(mot) + 1) * sizeof(char));
        strcpy(nouveau->mot, mot);
        nouveau->occurence = 1;
        nouveau->suivant = NULL;
    }
    return nouveau;
}

ListeOcc ajoute_mot_occs(ListeOcc liste, char* mot) {
    Occ* nouveau = alloue_occ(mot);
    if (nouveau != NULL) {
        nouveau->suivant = liste;
        liste = nouveau;
    }
    return liste;
}

int est_mot_dans_occs(ListeOcc liste, char* mot) {
    while (liste != NULL) {
        if (chaine_egales(mot, liste->mot)) {
            return 1;
        }
        liste = liste->suivant;
    }
    return 0;
}

void ajoute_occurence(ListeOcc liste, char* mot) {
    while (liste != NULL) {
        if (chaine_egales(mot, liste->mot)) {
            liste->occurence++;
            return;
        }
        liste = liste->suivant;
    }
}

ListeOcc compte_occurences(ListeMots liste) {
    ListeOcc occs = malloc(sizeof(ListeOcc));
    if (occs == NULL) {
        return occs;
    }
    while (liste != NULL) {
        if (liste->mot != NULL) {
            if (!est_mot_dans_occs(occs, liste->mot)) {
                occs = ajoute_mot_occs(occs, liste->mot);
            }
            else {
                ajoute_occurence(occs, liste->mot);
            }
        }
        liste = liste->precedent;
    }
    return occs;
}

void vide_occs(ListeOcc liste) {
    if (liste != NULL) {
        vide_occs(liste->suivant);
        free(liste->mot);
        free(liste);
    }
}

ListeOcc occurences_apres_mot(ListeMots liste, char* mot_cherche) {
    ListeOcc occs = malloc(sizeof(ListeOcc));
    if (occs == NULL) {
        return occs;
    }
    while (liste->precedent != NULL) {
        if (chaine_egales(liste->mot, mot_cherche)) {
            if (liste->suivant != NULL) {
                if (!est_mot_dans_occs(occs, liste->suivant->mot)) {
                    occs = ajoute_mot_occs(occs, liste->suivant->mot);
                }
                else {
                    ajoute_occurence(occs, liste->suivant->mot);
                }
            }
        }
        liste = liste->precedent;
    }
    return occs;
}

ListeOcc occurences_avant_mot(ListeMots liste, char* mot_cherche) {
    ListeOcc occs = malloc(sizeof(ListeOcc));
    if (occs == NULL) {
        return occs;
    }
    while (liste->precedent != NULL) {
        if (chaine_egales(liste->mot, mot_cherche)) {
            if (liste->precedent->precedent != NULL) {
                if (!est_mot_dans_occs(occs, liste->precedent->mot)) {
                    occs = ajoute_mot_occs(occs, liste->precedent->mot);
                }
                else {
                    ajoute_occurence(occs, liste->precedent->mot);
                }
            }
        }
        liste = liste->precedent;
    }
    return occs;
}

ListeOcc compte_decoupage(ListeMots liste, int decoupe) {
    ListeMots liste_r;
    ListeMots liste_decoupe;
    ListeOcc occs;
    liste_r = renverse_liste(liste);
    liste_decoupe = decoupe_liste(liste_r, decoupe);
    occs = compte_occurences(liste_decoupe);
    vide_liste(liste_r);
    vide_liste(liste_decoupe);
    return occs;
}

