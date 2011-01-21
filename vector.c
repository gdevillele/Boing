/*
 *  vector.c
 *  Boing
 *
 *  Created by Gaëtan de Villèle on 15/01/11.
 *  Copyright 2011 EPSI. All rights reserved.
 *
 */



#include "vector.h"



// CREATE VECTOR
Vector Vector_create()
{
	Vector v;
	v.x = (float)0;
	v.y = (float)0;
	v.z = (float)0;
	return v;
}


/////////////////////////////////////////////////////////////////
//	ADDITION - Retourne le vecteur résultant de l'addition de 2 vecteurs
/////////////////////////////////////////////////////////////////
Vector vector_addition(Vector v1, Vector v2)
{
	Vector v;
	v.x = v1.x + v2.x ;
	v.y = v1.y + v2.y ;
	v.z = v1.z + v2.z ;
	return v;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	SOUSTRACTION - Retourne le vecteur résultant de la soustraction du 1er vecteur par le 2eme (v1 - v2)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Vector vector_soustraction(Vector v1, Vector v2)
{
	Vector v;
	v.x = v1.x - v2.x ;
	v.y = v1.y - v2.y ;
	v.z = v1.z - v2.z ;
	return v;
}

///////////////////////////////////////
//	Retourne la NORME du vecteur
///////////////////////////////////////
float vector_norm(Vector v)
{
	return sqrt( (v.x)*(v.x) + (v.y)*(v.y) + (v.z)*(v.z) );
}





void tabVector_add( TabVector* tabv, Vector* vect )
{
	// On augmente la taille du tableau de pointeurs sur Vector
	tabv->size++;
	// On Réaloue la mémoire pour le tableau
	tabv->tab = realloc( tabv->tab, tabv->size * sizeof(Vector*) );
	// On stocke dans la dernière case le vector
	tabv->tab[tabv->size-1] = vect;
}


TabVector tabVector_create()
{
	TabVector tv;
	tv.size = 0;
	tv.tab = NULL;
	tv.tab = malloc( 0 * sizeof(Vector*) );
	return tv;
}























