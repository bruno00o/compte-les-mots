/**
 * @file Tri.h
 * @author bruno00o
 * @brief Gestion des tris
 * @date 2022-03-15
 */

#ifndef __TRI__
#define __TRI__

#include "Occurences.h"
#include "Chaine.h"

 /**
  * @brief Inverse deux mots de la liste
  *
  * @param mot_1
  * @param mot_2
  */
void inverse_mots(Occ* mot_1, Occ* mot_2);

/**
 * @brief Effectue un tri à bulle pour trier les mots de la liste d'occurences
 * dans l'ordre lexicographique
 *
 * @param liste
 * @return ListeOcc
 */
ListeOcc tri_lexico(ListeOcc liste);

/**
 * @brief Effectue un tri à bulle pour trier les mots de la liste d'occurences
 * dans l'ordre du nombre d'occurences
 *
 * @param liste
 * @return ListeOcc
 */
ListeOcc tri_occurences(ListeOcc liste);

#endif