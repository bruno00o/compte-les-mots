/**
 * @file Chaine.h
 * @author bruno00o
 * @brief Fonctions de comparaisons des chaines de caractères
 * @date 2022-03-15
 */

#ifndef __CHAINE__
#define __CHAINE__

#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

 /**
  * @brief Retourne 1 si chaine1 et chaine2 sont identiques 0 sinon
  *
  * @param chaine1
  * @param chaine2
  * @return int
  */
int chaine_egales(char* chaine1, char* chaine2);

/**
 * @brief Retourne 1 si chaine1 est inférieure à chaine2 0 sinon
 *
 * @param chaine1
 * @param chaine2
 * @return int
 */
int compare_chaines(char* chaine1, char* chaine2);

#endif