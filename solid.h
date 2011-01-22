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
#include "draw.h"


//--------------------------------------------
//	STRUCTURE
//--------------------------------------------
typedef struct Solid
{
	// solid color (rgb)
	int color[3];
	
	// Vertices
	TabVector verticesArray;
	
	// Rayon du cercle circonscrit
	float radius;
	
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
	// Les angles sont en radians
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
float*	solid_getExternalAura( Solid *solid );





#endif // SOLID


