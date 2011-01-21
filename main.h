/////////////////////////////////////////////////////////////
///
///		main.h
///		Boing
///
///		Created by Gaëtan de Villèle on 15/01/11.
///		Copyright 2011 EPSI. All rights reserved.
///
/////////////////////////////////////////////////////////////


#ifndef MAIN // Si la constante n'a pas été définie` le fichier n'a jamais été inclus
#define MAIN // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus



//------------------------------------------
// Bibliothèques principales
//------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



//------------------------------------------
///	Bibliothèques additionnelles
//------------------------------------------
#include "SDL.h"
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"



//------------------------------------------
// Moteur Physique
//------------------------------------------
#include "vector.h"
#include "solid.h"
#include "physicEngine.h"




#endif // MAIN