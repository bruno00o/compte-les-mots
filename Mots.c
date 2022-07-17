/**
 * @file Mots.c
 * @author bruno00o
 * @brief Gestion des listes de mots
 * @date 2022-03-15
 */

#include "Mots.h"

char* fichier_vers_chaine(FILE* f) {
    char* texte = malloc(sizeof(char) * 2048);
    char c;
    char espace = ESPACE;
    while ((c = fgetc(f)) != EOF) {
        if ('A' <= c && 'Z' >= c) {
            c = c + 'a' - 'A';
        }
        if (ispunct(c)) {
            strncat(texte, &espace, 1);
        }
        else if (!isblank(c) && c != '\n') {
            strncat(texte, &c, 1);
        }
        else {
            strncat(texte, &espace, 1);
        }
    }
    return texte;
}

Mot* alloue_mot(char* mot) {
    Mot* nouveau = malloc(sizeof(Mot));
    if (nouveau != NULL) {
        nouveau->mot = malloc((strlen(mot) + 1) * sizeof(char));
        strcpy(nouveau->mot, mot);
        nouveau->suivant = NULL;
    }
    return nouveau;
}

ListeMots ajoute_mot(ListeMots liste, char* mot) {
    Mot* nouveau = alloue_mot(mot);
    if (nouveau != NULL) {
        nouveau->precedent = liste;
        liste = nouveau;
        liste->precedent->suivant = liste;
    }
    return liste;
}

int est_mot_valide(char* mot) {
    int i;
    i = 0;
    while (mot[i] != '\0') {
        if ('a' > mot[i] || 'z' < mot[i]) {
            return 0;
        }
        i++;
    }
    if (strlen(mot) <= 0)
        return 0;
    return 1;
}

ListeMots chaine_vers_liste(char* texte) {
    int i;
    char* mot = malloc(sizeof(char) * 128);
    ListeMots liste = malloc(sizeof(ListeMots));
    if (liste == NULL) {
        return liste;
    }
    i = 0;
    mot[0] = '\0';
    while (texte[i] != '\0') {
        if (texte[i] != ESPACE) {
            strncat(mot, &texte[i], 1);
        }
        else {
            if (est_mot_valide(mot))
                liste = ajoute_mot(liste, mot);
            mot[0] = '\0';
        }
        i++;
    }
    if (est_mot_valide(mot))
        liste = ajoute_mot(liste, mot);
    free(mot);
    return liste;
}

void vide_liste(ListeMots liste) {
    if (liste != NULL) {
        vide_liste(liste->precedent);
        free(liste->mot);
        free(liste);
    }
}

ListeMots renverse_liste(ListeMots liste) {
    ListeMots liste_r = malloc(sizeof(ListeMots));
    while (liste != NULL) {
        if (liste->mot != NULL) {
            liste_r = ajoute_mot(liste_r, liste->mot);
        }
        liste = liste->precedent;
    }
    return liste_r;
}

int est_mot_valide_decoupage(char* mot, int decoupe) {
    int cmpt, i;
    i = 0;
    cmpt = 0;
    while (mot[i] != '\0') {
        if (mot[i] == ESPACE && mot[i + 1] != '\0') {
            cmpt++;
        }
        i++;
    }
    if (cmpt == decoupe - 1) {
        return 1;
    }
    return 0;
}

ListeMots decoupe_liste(ListeMots liste, int decoupe) {
    int i;
    char espace;
    ListeMots curseur;
    char* mot = malloc(sizeof(char) * 1024);
    ListeMots nouveau = malloc(sizeof(ListeMots));
    espace = ESPACE;
    curseur = liste;
    nouveau->mot = NULL;
    while (liste != NULL) {
        if (liste->mot != NULL) {
            for (i = 0; i < decoupe; i++) {
                if (curseur->precedent != NULL) {
                    if (curseur->mot != NULL) {
                        strncat(mot, curseur->mot, strlen(curseur->mot));
                        if (i != decoupe - 1)
                            strncat(mot, &espace, 1);
                    }
                    curseur = curseur->precedent;
                }
            }
        }
        if (est_mot_valide_decoupage(mot, decoupe))
            nouveau = ajoute_mot(nouveau, mot);
        mot[0] = '\0';
        liste = liste->precedent;
        curseur = liste;
    }
    free(mot);
    return nouveau;
}