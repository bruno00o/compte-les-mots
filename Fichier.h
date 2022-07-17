/**
 * @file Fichier.h
 * @author bruno00o
 * @brief Gestion des fichiers
 * @date 2022-03-15
 */

#ifndef __FICHIER__
#define __FICHIER__

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Ouvre un fichier
 * 
 * @param nomfichier 
 * @return FILE* 
 */
FILE* ouvrir_fichier(const char* nomfichier);

/**
 * @brief Ferme un fichier
 * 
 * @param nomfichier 
 */
void fermer_fichier(FILE* nomfichier);

#endif