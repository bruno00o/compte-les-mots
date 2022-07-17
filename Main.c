/**
 * @file Main.c
 * @author bruno00o
 * @brief Programme permettant de compter les mots d'un fichier
 * TP6 - Perfectionnement à la programmation en C
 * @date 2022-03-15
 */

#include "Test.h"
#include "Affichage.h"

/**
 * @brief Appelle les fonctions correspondant à l'option -s
 * 
 * @param argc 
 * @param argv 
 * @param liste 
 * @return ListeOcc 
 */
ListeOcc option_s(int argc, char* argv[], ListeMots liste) {
    ListeOcc occs;
    char* chaine = recherche_chaine(argc, argv, "-s");
    if (chaine != NULL) {
        occs = occurences_apres_mot(liste, chaine);
    }
    else
        occs = NULL;
    return occs;
}

/**
 * @brief Appelle les fonctions correspondant à l'option -p
 * 
 * @param argc 
 * @param argv 
 * @param liste 
 * @return ListeOcc 
 */
ListeOcc option_p(int argc, char* argv[], ListeMots liste) {
    ListeOcc occs;
    char* chaine = recherche_chaine(argc, argv, "-p");
    if (chaine != NULL) {
        occs = occurences_avant_mot(liste, chaine);
    }
    else
        occs = NULL;
    return occs;
}

/**
 * @brief Appelle les fonctions correspondant à l'option -e
 * 
 * @param argc 
 * @param argv 
 * @param liste 
 * @return ListeOcc 
 */
ListeOcc option_e(int argc, char* argv[], ListeMots liste) {
    ListeOcc occs;
    int decoupe;
    decoupe = recherche_int_e(argc, argv, "-e");
    if (decoupe) {
        occs = compte_decoupage(liste, decoupe);
    }
    else {
        occs = NULL;
        fprintf(stderr, "L'option -e doit être suivi d'un nombre supérieur à 0\n");
    }
    return occs;
}

/**
 * @brief Entrée du programme avec gestion des options
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
    int options[6];
    ListeMots liste;
    ListeOcc occs;
    FILE* f;
    char* texte;
    if (lit_args(argc, argv, options)) {
        f = ouvrir_fichier(argv[1]);
        if (options[5] && test()) {
            printf("L'ensemble des tests ont été réalisés avec succès\n");
        }
        if (f != NULL) {
            texte = fichier_vers_chaine(f);
            liste = chaine_vers_liste(texte);
            if (!options[2] && !options[3] && !options[4]) {
                occs = compte_occurences(liste);
            }
            if (options[2]) {
                occs = option_s(argc, argv, liste);
            }
            if (options[3]) {
                occs = option_p(argc, argv, liste);
            }
            if (options[4]) {
                occs = option_e(argc, argv, liste);
            }
            if (options[0]) {
                occs = tri_lexico(occs);
            }
            if (options[1]) {
                occs = tri_occurences(occs);
            }
            if (occs != NULL) {
                afficher_occs(occs);
                vide_occs(occs);
            }
            fermer_fichier(f);
            vide_liste(liste);
            free(texte);
        }

    }
    return 0;
}