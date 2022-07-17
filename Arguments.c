/**
 * @file Arguments.c
 * @author bruno00o
 * @brief Gestion des arguments et des options lors de l'exécution
 * @date 2022-03-15
 */

#include "Arguments.h"

int verif_s_p(int options[NB_OPTIONS]) {
    if (options[2] == options[3] && options[2] == 1) {
        fprintf(stderr, "Les arguments -s et -p ne peuvent pas être utilisés en même temps\n");
        return 0;
    }
    return 1;
}

int lit_args(int argc, char* argv[], int options[NB_OPTIONS]) {
    int i;
    FILE* f;
    if (argc < 2) {
        fprintf(stderr, "Le 2ème argument doit être le fichier texte à compter\n");
        return 0;
    }
    for (i = 0; i < NB_OPTIONS; i++) {
        options[i] = 0;
    }
    for (i = 1; i < argc; i++) {
        if (chaine_egales("-a", argv[i]))
            options[0] = 1;
        if (chaine_egales("-n", argv[i]))
            options[1] = 1;
        if (chaine_egales("-s", argv[i]))
            options[2] = 1;
        if (chaine_egales("-p", argv[i]))
            options[3] = 1;
        if (chaine_egales("-e", argv[i]))
            options[4] = 1;
        if (chaine_egales("-test", argv[i]))
            options[5] = 1;
    }
    if (argc == 2 && !options[5]) {
        if ((f = fopen(argv[1], "r"))) {
            fclose(f);
        }
        else {
            fprintf(stderr, "Ce fichier ne peut pas être ouvert\n");
            return 0;
        }
    }
    return verif_s_p(options);
}

char* recherche_chaine(int argc, char* argv[], char* opt) {
    int i;
    char* res;
    for (i = 2; i < argc; i++) {
        if (chaine_egales(opt, argv[i])) {
            if (i + 1 < argc)
                res = argv[i + 1];
            else {
                fprintf(stderr, "L'option %s doit être suivi d'une chaine de caractères\n", opt);
                return NULL;
            }
        }
    }
    return res;
}

int recherche_int_e(int argc, char* argv[], char* opt) {
    int i;
    int res;
    for (i = 2; i < argc; i++) {
        if (chaine_egales(opt, argv[i])) {
            if (i + 1 < argc)
                res = atoi(argv[i + 1]);
            else {
                return 0;
            }
        }
    }
    return res;
}