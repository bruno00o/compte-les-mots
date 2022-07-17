/**
 * @file Test.h
 * @author bruno00o
 * @brief Module de test des principales fonctions
 * @date 2022-03-15
 */

#ifndef __TEST__
#define __TEST__

#include <assert.h>
#include "Mots.h"
#include "Fichier.h"
#include "Chaine.h"
#include "Occurences.h"
#include "Arguments.h"
#include "Tri.h"

int test(void);
int test_chaine_egales();
int test_fichier_vers_chaine();
int test_est_mot_valide();
void afficher_liste(ListeMots liste);
ListeMots test_chaine_vers_liste(char* texte);
ListeOcc test_compte_occurences(ListeMots liste);
int test_compare_chaines();
ListeOcc test_tri_lexico(ListeOcc occs);
ListeOcc test_tri_occurences(ListeOcc occs);
ListeOcc test_occurences_apres_mot(ListeMots liste, ListeOcc occs);


#endif