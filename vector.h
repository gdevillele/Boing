//////////////////////////////////////////////////////////////////
///
///		vector.h
///		Boing
///
///		Created by Gaëtan de Villèle on 15/01/11.
///		Copyright 2011 EPSI. All rights reserved.
///
//////////////////////////////////////////////////////////////////

#ifndef VECTOR
#define VECTOR


#include <math.h>




//----------------------------------------------------
//	STRUCTURE
//----------------------------------------------------

typedef struct Vector
{
	// Composante sur X
	float x;
	
	// Composante sur Y
	float y;
	
	// Composante sur Z (hors du plan - pour les vecteurs moment/rotation)
	float z;
	
} Vector;



//----------------------------------------------------
//	FUNCTIONS
//----------------------------------------------------

Vector		vector_addition(Vector v1, Vector v2);
float		vector_norm(Vector v);





#endif // VECTOR