/*
 *  vector.c
 *  Boing
 *
 *  Created by Gaëtan de Villèle on 15/01/11.
 *  Copyright 2011 EPSI. All rights reserved.
 *
 */



#include "vector.h"



/////////////////////////////////////////////////////////////////
//	Retourne le vecteur résultant de l'addition de 2 vecteurs
/////////////////////////////////////////////////////////////////
Vector vector_addition(Vector v1, Vector v2)
{
	Vector v;
	v.x = v1.x + v2.x ;
	v.y = v1.y + v2.y ;
	v.z = v1.z + v2.z ;
	return v;
}

///////////////////////////////////////
//	Retourne la NORME du vecteur
///////////////////////////////////////
float vector_norm(Vector v)
{
	int norm;
	norm = sqrt( (v.x)*(v.x) + (v.y)*(v.y) + (v.z)*(v.z) );
	return norm;
}