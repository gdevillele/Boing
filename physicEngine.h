/*
 *  physicEngine.h
 *  Boing
 *
 *  Created by Gaëtan de Villèle on 15/01/11.
 *  Copyright 2011 EPSI. All rights reserved.
 *
 */

#ifndef PHYSIC_ENGINE
#define PHYSIC_ENGINE



#include "OpenGL/gl.h"
#include "OpenGL/glu.h"

#include "vector.h"
#include "solid.h"

// Indication de la taille de la fenetre
void physicEngine_setWindowSize( int win_x_min, int win_x_max, int win_y_min, int win_y_max );

// 1 - Calcul des nouvelles positions
void physicEngine_computeNextPositions( int gap );

// 2 - Elimination des solids hors champ
void physicEngine_removeUselessSolids();

// 3 - Detection des collisions
void physicEngine_detectCollisions();


// 4 - Mise à jour de l'état des solides
void physicEngine_updateSolidsState( int gap );

// 5 - Affichage des solids
void physicEngine_display();


// Ajouter un solid au moteur
void physicEngine_add_solid( Vector position, Vector speed, Vector acceleration, int nb_of_faces, double radius, int staticSolid );

// Supprimer un solid
void physicEngine_removeSolid(int index);

// Libération de la mémoire
void physicEngine_free();


#endif // PHYSIC_ENGINE