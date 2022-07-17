/**
 * @file Mots.h
 * @author bruno00o
 * @brief Gestion des listes de mots
 * @date 2022-03-15
 */

#ifndef __MOTS__
#define __MOTS__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ESPACE ' '


 /**
  * @brief Structure permettant de modéliser une suite de mots sous l 
  * forme d'une liste chaîné. Ici le chainage est réaliser avecle 
  * mot precedent !
  */
typedef struct _mot {
    char* mot;
    struct _mot* suivant;
    struct _mot* precedent;
} Mot, * ListeMots;

/**
 * @brief Prends un fichier et retourne ce même fichier sous forme d'une
 * chaine de caractères
 *
 * @param f
 * @return char*
 */
char* fichier_vers_chaine(FILE* f);

/**
 * @brief Retourne un mot alloué avec le mot mot
 *
 * @param mot
 * @return Mot*
 */
Mot* alloue_mot(char* mot);

/**
 * @brief Ajoute un mot en tête de la liste liste avec le mot mot
 *
 * @param liste
 * @param mot
 * @return ListeMots
 */
ListeMots ajoute_mot(ListeMots liste, char* mot);

/**
 * @brief Retourne 1 si le mot mot est valide c'est à dire qu'il n'est composé
 * que de lettres comprises entre 'a' et 'z'
 *
 * @param mot
 * @return int
 */
int est_mot_valide(char* mot);

/**
 * @brief Retourne une liste de mots à partir de la chaine de caractères texte
 *
 * @param texte
 * @return ListeMots
 */
ListeMots chaine_vers_liste(char* texte);

/**
 * @brief Vide la liste liste et la free
 *
 * @param liste
 */
void vide_liste(ListeMots liste);

/**
 * @brief Retourne la liste liste après avoir été renversée
 *
 * @param liste
 * @return ListeMots
 */
ListeMots renverse_liste(ListeMots liste);

/**
 * @brief Retourne 1 si le mot est valide pour la liste découpée
 *
 * @param mot
 * @param decoupe
 * @return int
 */
int est_mot_valide_decoupage(char* mot, int decoupe);

/**
 * @brief Découpe une liste avec un nombre decoupe de mot dans chaques mots
 * de la liste
 *
 * @param liste
 * @param decoupe
 * @return ListeMots
 */
ListeMots decoupe_liste(ListeMots liste, int decoupe);

#endif