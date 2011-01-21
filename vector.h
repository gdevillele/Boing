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
Vector		Vector_create();
Vector		vector_addition(Vector v1, Vector v2);
Vector		vector_soustraction(Vector v1, Vector v2);
float		vector_norm(Vector v);







//--------------------------------------------------------------------
//	TABVECTOR - Tableau de vecteurs (position) pour les sommets
//--------------------------------------------------------------------

typedef struct TabVector
{
	// Tableau dynamique de pointeurs de Vector
	Vector*		*tab;
	
	// Taille du tableau
	int			size;
	
} TabVector;

// Creation d'un tab vecteur avec initialisation
TabVector tabVector_create();

// Ajouter un Vector à un TabVector
void tabVector_add( TabVector* tabv, Vector* vect );







#endif // VECTOR