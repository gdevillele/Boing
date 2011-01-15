////////////////////////////////////////////////////////////////////
///
///		@name			: solid.h
///		@description	: describe the solid type
///		@project		: Boing
///
///		Created by Gaëtan de Villèle on 15/01/11.
///		Copyright 2011 EPSI. All rights reserved.
///
////////////////////////////////////////////////////////////////////

#ifndef SOLID
#define SOLID


#include <math.h>
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#include "vector.h"


//--------------------------------------------
//	STRUCTURE
//--------------------------------------------
typedef struct Solid
{
	// solid color (rgb)
	int color[3];
	
	// Number of Vertices
	int nb_vertices;
	
	// Rayon du cercle circonscrit
	double radius;
	
	// static solid (as a boolean - 0=nonstatic)
	int staticSolid;
	
	
	// TRANSLATION
	//------------------------------
	// vecteur position
	Vector position;
	
	// vecteur position suivante
	Vector nextPosition;
	
	// vecteur vitesse
	Vector speed;
	
	// vecteur acceleration
	Vector acceleration;
	
	// ROTATION
	//-------------------------------
	// vecteur moment/rotation
	// Position en rotation (angle)
	// float/int angle;
	// Vecteur vitesse de rotation
	// Vector rotation;
	// Vecteur acceleration de la rotation
	// Vector accel_rotation;
} Solid;





//--------------------------------------------
//	FUNCTIONS
//--------------------------------------------
void	solid_display( Solid *solid );
void	solid_updatePosition( Solid *solid, int gap );
void	solid_updateSpeed( Solid *solid, int gap );
void	solid_updateNextPosition( Solid *solid, int gap );





#endif // SOLID






/////////////////////////////////////////////////////////////////////////////////////////
//	BROUILLON - OLD
////////////////////////////////////
/*
 // Génération des points (sommets) des solids
 
 int   i = 0;
 float a  = Pi()    / object->nbVertices;
 float da = TwoPi() / object->nbVertices;
 
 for( i = 0; i < object->nbVertices; i ++)
 {
 a += da;
 
 object->vertices[i].x = cos(a) * angle;
 object->vertices[i].y = sin(a) * angle;
 }
 */


