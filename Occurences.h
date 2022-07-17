/**
 * @file Occurences.h
 * @author bruno00o
 * @brief Gestion des listes d'occurrences
 * @date 2022-03-15
 */

#ifndef __OCCURENCES__
#define __OCCURENCES__

#include <stdio.h>
#include "Mots.h"
#include "Chaine.h"

 /**
  * @brief Stucture permettant de modéliser chaque mot et son nombre
  * d'occurence sous la forme d'une liste chaîné. 
  */
typedef struct _occ {
    char* mot;
    int occurence;
    struct _occ* suivant;
} Occ, * ListeOcc;

/**
 * @brief Alloue un nouveau mot pour la liste d'occurences
 *
 * @param mot
 * @return Occ*
 */
Occ* alloue_occ(char* mot);

/**
 * @brief Ajoute un mot en tête de la liste d'occurences
 *
 * @param liste
 * @param mot
 * @return ListeOcc
 */
ListeOcc ajoute_mot_occs(ListeOcc liste, char* mot);

/**
 * @brief Retourne 1 si le mot mot est déjà dans la liste d'occurences
 *
 * @param liste
 * @param mot
 * @return int
 */
int est_mot_dans_occs(ListeOcc liste, char* mot);

/**
 * @brief Ajoute une occurence à un mot dans la liste (+1)
 *
 * @param liste
 * @param mot
 */
void ajoute_occurence(ListeOcc liste, char* mot);

/**
 * @brief Compte les occurences des mots dans la liste liste
 *
 * @param liste
 * @return ListeOcc
 */
ListeOcc compte_occurences(ListeMots liste);

/**
 * @brief Vide la liste des occurences liste
 *
 * @param liste
 */
void vide_occs(ListeOcc liste);

/**
 * @brief Comptes les occurences des mots placés après mot_recherche dans la
 * liste liste
 *
 * @param liste
 * @param mot_cherche
 * @return ListeOcc
 */
ListeOcc occurences_apres_mot(ListeMots liste, char* mot_cherche);

/**
 * @brief Comptes les occurences des mots placés avant mot_recherche dans la
 * liste
 *
 * @param liste
 * @param mot_cherche
 * @return ListeOcc
 */
ListeOcc occurences_avant_mot(ListeMots liste, char* mot_cherche);

/**
 * @brief Appelle les autres fonctions pour renverser la liste, découper la liste
 * puis comptes les occurences
 *
 * @param liste
 * @param decoupe
 * @return ListeOcc
 */
ListeOcc compte_decoupage(ListeMots liste, int decoupe);

#endif