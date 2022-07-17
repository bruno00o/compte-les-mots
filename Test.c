/**
 * @file Test.c
 * @author bruno00o
 * @brief Module de test des principales fonctions
 * @date 2022-03-15
 */

#include "Test.h"

int test_chaine_egales() {
    int val;
    char* t1 = "test";
    char* t2 = "test1";
    char* t3 = "test";
    val = !chaine_egales(t1, t2);
    val += chaine_egales(t1, t3);
    if (val != 2) {
        fprintf(stderr, "Erreur dans chaine_egales()\n");
    }
    return val;
}

int test_fichier_vers_chaine() {
    int val;
    char* texte;
    FILE* f = ouvrir_fichier("test.txt");
    char* res = "trois un un un1un deux deux deux deuxdeux un quatre4";
    if (f == NULL) {
        fprintf(stderr, "Le fiichier test.txt est manquant\n");
        assert(f != NULL);
    }
    texte = fichier_vers_chaine(f);
    val = chaine_egales(texte, res);
    if (!val)
        fprintf(stderr, "Le texte de test.txt n'est pas égal au texte renvoyé par fichier_vers_chaine()\n");
    fermer_fichier(f);
    free(texte);
    return val;
}

int test_est_mot_valide() {
    int val;
    char* valide = "test";
    char* invalide = "test1";
    val = est_mot_valide(valide);
    val += !est_mot_valide(invalide);
    if (val != 2)
        fprintf(stderr, "Erreur lors de l'ajout d'un nouveau mot pour ajoute_mot()\n");
    return val;
}

void afficher_liste(ListeMots liste) {
    while (liste != NULL) {
        printf("-> %s ", liste->mot);
        liste = liste->precedent;
    }
    printf("\n");
}

ListeMots test_chaine_vers_liste(char* texte) {
    int retour;
    ListeMots liste;
    liste = chaine_vers_liste(texte);
    if (!liste)
        return NULL;
    retour = chaine_egales("lorem", liste->mot);
    retour += chaine_egales("ipsum", liste->precedent->mot);
    retour += chaine_egales("lorem", liste->precedent->precedent->mot);
    if (retour != 3) {
        fprintf(stderr, "Erreur lors de la création d'une liste de mot dans chaine_vers_liste()\n");
        assert(retour == 3);
    }
    return liste;
}

ListeOcc test_compte_occurences(ListeMots liste) {
    int retour;
    ListeOcc occs;
    occs = compte_occurences(liste);
    retour = occs->occurence;
    retour += occs->suivant->occurence;
    if (retour != 3)
        fprintf(stderr, "Erreur de comptage dans compte_occurences\n");
    assert(retour == 3);
    return occs;
}

int test_compare_chaines() {
    int val;
    char* t1 = "a";
    char* t2 = "b";
    val = compare_chaines(t1, t2);
    val += !compare_chaines(t2, t1);
    if (!val) {
        fprintf(stderr, "Erreur dans compare_chaines()\n");
    }
    return val;
}

ListeOcc test_tri_lexico(ListeOcc occs) {
    int retour;
    occs = tri_lexico(occs);
    retour = compare_chaines("ipsum", occs->mot);
    retour += compare_chaines("lorem", occs->suivant->mot);
    if (retour != 2) {
        fprintf(stderr, "Erreur de comptage dans tri_lexico\n");
        assert(retour == 2);
    }
    return occs;
}

ListeOcc test_tri_occurences(ListeOcc occs) {
    int retour;
    occs = tri_occurences(occs);
    retour = compare_chaines("lorem", occs->mot);
    retour += compare_chaines("ipsum", occs->suivant->mot);
    if (retour != 2) {
        fprintf(stderr, "Erreur de comptage dans tri_occurences\n");
        assert(retour == 2);
    }
    return occs;
}

ListeOcc test_occurences_apres_mot(ListeMots liste, ListeOcc occs) {
    int val;
    occs = occurences_apres_mot(liste, "lorem");
    val = chaine_egales("ipsum", occs->mot);
    if (!val) {
        fprintf(stderr, "Erreur dans occurences_apres_mot()\n");
        assert(val);
    }
    return occs;
}

int test() {
    ListeMots liste;
    ListeOcc occs;
    char* texte = "lorem ipsum lorem";
    if (!test_chaine_egales()) return 0;
    if (!test_est_mot_valide()) return 0;
    if (!test_compare_chaines()) return 0;
    if (!test_fichier_vers_chaine()) return 0;

    if (!(liste = test_chaine_vers_liste(texte))) return 0;
    if (!(occs = test_compte_occurences(liste))) return 0;
    if (!(occs = test_tri_lexico(occs))) return 0;
    if (!(occs = test_tri_occurences(occs))) return 0;

    if (!(occs = test_occurences_apres_mot(liste, occs))) return 0;
    return 1;
}