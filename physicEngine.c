//////////////////////////////////////////////////////////
///
///	physicEngine.c
///	Boing
///
///	Created by Gaëtan de Villèle on 15/01/11.
///	Copyright 2010 EPSI. All rights reserved.
///
//////////////////////////////////////////////////////////


#include "physicEngine.h"


//-------------------------------------------------------
//	VARIABLES
//-------------------------------------------------------

	// Tableau des Solids
	//--------------------
	int		sizeTabSolids	= 0;
	Solid*	*tabSolids		= NULL;

	// Window size
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;






//-------------------------------------------------------
//	FONCTIONS
//-------------------------------------------------------


// Définition des dimensions de la fenetre
void physicEngine_setWindowSize( int win_x_min, int win_x_max, int win_y_min, int win_y_max )
{
	x_min = win_x_min;
	x_max = win_x_max;
	y_min = win_y_min;
	y_max = win_y_max;
}












// 1 - Calcul des nouvelles positions
void physicEngine_computeNextPositions( int gap )
{
	int i;
	for ( i=0 ; i<sizeTabSolids ; i++ )
	{
		if( tabSolids[i]->staticSolid == 0 )
		{
			solid_updateNextPosition( tabSolids[i], gap );
		}
	}
}

// 2 - Elimination des solids hors champ
void physicEngine_removeUselessSolids()
{
	int i;
	for ( i=0 ; i<sizeTabSolids ; i++ )
	{
		if( tabSolids[i]->position.x < (x_min-tabSolids[i]->radius) ||
		    tabSolids[i]->position.x > (x_max+tabSolids[i]->radius) ||
		    tabSolids[i]->position.y < (y_min-tabSolids[i]->radius) ||
		    tabSolids[i]->position.y > (y_max+tabSolids[i]->radius) )
		{
			// Supprimer le solid du tableau de solids
			physicEngine_removeSolid(i);
			//printf("%i\n", sizeTabSolids);
		}
	}
}


// 3 - Detection des collisions
void physicEngine_detectCollisions()
{
	int i;
	for ( i=0 ; i<sizeTabSolids ; i++ )
	{
		
	}
}


// 4 - Mise à jour de l'état des solides
void physicEngine_updateSolidsState( int gap )
{
	int i;
	for ( i=0 ; i<sizeTabSolids ; i++ )
	{
		if( tabSolids[i]->staticSolid == 0 )
		{
			solid_updatePosition( tabSolids[i], gap );
			solid_updateSpeed( tabSolids[i], gap );
		}
	}
}

// 5 - Affichage de tous les solids contenus dans le tableau
void physicEngine_display()
{
	int i;
	
	// On dessine tous les solids 
	for ( i=0 ; i<sizeTabSolids ; i++ )
	{
		solid_display( tabSolids[i] );
	}
}





// Supprimer un solid
//-------------------------------------------
void physicEngine_removeSolid(int index)
{
	int i;
	
	sizeTabSolids--;
	for ( i=index ; i < sizeTabSolids ; i++ )
	{
		tabSolids[i] = tabSolids[i+1];
	}
	tabSolids = realloc( tabSolids, sizeTabSolids * sizeof(Solid*) );
}




//	Ajouter un solid
//----------------------------------------
void physicEngine_add_solid( Vector position, Vector speed, Vector acceleration, int nb_of_faces, double radius, int staticSolid )
{
	// Augmente la taille du tableau de Solids
	sizeTabSolids++;
	if(sizeTabSolids <= 1)
	{
		tabSolids = malloc( sizeTabSolids * sizeof(Solid*) );
	} else {
		tabSolids = realloc( tabSolids, sizeTabSolids * sizeof(Solid*) );
	}
	
	Solid *solid		= malloc( sizeof(Solid) * 1);
	solid->position		= position;
	solid->speed		= speed;
	solid->acceleration = acceleration;
	
	solid->nb_vertices	= nb_of_faces;
	solid->radius		= radius;
	solid->staticSolid  = staticSolid;
	
	solid->color[0]		= rand()%255;
	solid->color[1]		= rand()%255;
	solid->color[2]		= rand()%255;
	
	// Ajouter le solide au tableau
	tabSolids[sizeTabSolids-1] = solid;
}



// Libération de la mémoire
//-----------------------------------
void physicEngine_free()
{
	int i = 0;
	for (i=0; i<sizeTabSolids; i++)
	{
		free(tabSolids[i]);
	}
	free(tabSolids);
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRESSE PAPIER
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




// Collisions
/*
 for ( i=0 ; i<sizeTabSolids ; i++ )
 {
 if( tabSolids[i]->position.y <= (-384+25) )
 {
 tabSolids[i]->position.y = -384+25;
 tabSolids[i]->speed.y = -( tabSolids[i]->speed.y )/(1.1);
 }
 if( tabSolids[i]->position.x >= (512 - 25) )
 {
 tabSolids[i]->position.x = (512 - 25);
 tabSolids[i]->speed.x = -( tabSolids[i]->speed.x )*(2);
 }
 if( tabSolids[i]->position.x <= (-512 + 25) )
 {
 tabSolids[i]->position.x <= (-512 + 25);
 tabSolids[i]->speed.x = -( tabSolids[i]->speed.x )*(2);
 }
 }*/





