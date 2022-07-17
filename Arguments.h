/**
 * @file Arguments.h
 * @author bruno00o
 * @brief Gestion des arguments et des options lors de l'exécution
 * @date 2022-03-15
 */

#ifndef __ARGUMENTS__
#define __ARGUMENTS__

#include <stdlib.h>
#include "Chaine.h"

#define NB_OPTIONS 6

 /**
  * @brief Lit les arguments passés en paramètre (ceux de l'execution
  * du programme) retourne 1 si tout se passe bien 0 sinon
  * Les options choisies par l'utilisateur passent dans options[NB_OPTIONS]
  *
  * @param argc
  * @param argv
  * @param options
  * @return int
  */
int lit_args(int argc, char* argv[], int options[NB_OPTIONS]);

/**
 * @brief Retourne la chaine de caractères se trouvant après l'arguments opt
 * dans la liste argv
 *
 * @param argc
 * @param argv
 * @param opt
 * @return char*
 */
char* recherche_chaine(int argc, char* argv[], char* opt);

/**
 * @brief Retourne l'entier se trouvant après l'argument opt dans la liste argv
 *
 * @param argc
 * @param argv
 * @param opt
 * @return int
 */
int recherche_int_e(int argc, char* argv[], char* opt);

/**
 * @brief Vérifie que les options s et p ne soient pas utilisées en même temps
 *
 * @param options
 * @return int
 */
int verif_s_p(int options[NB_OPTIONS]);

#endif