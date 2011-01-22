////////////////////////////////////////////////////////////////////
///
///		@name			: solid.c
///		@description	: implements the solid type functions
///		@project		: Boing
///
///		Created by Gaëtan de Villèle on 15/01/11.
///		Copyright 2011 EPSI. All rights reserved.
///
////////////////////////////////////////////////////////////////////


#include "solid.h"


//	Affiche un Solid
//----------------------------------------
void solid_display(Solid *solid)	// Génération des points (sommets) des solids
{
	// Variables
	int		i	= 0;
	
	//glBegin(GL_LINE_LOOP); 
	glBegin(GL_POLYGON);
	glColor3ub( solid->color[0], solid->color[1], solid->color[2] );
	
	for( i = 0; i < solid->verticesArray.size; i++ )
	{
		glVertex2f( ( solid->position.x + solid->verticesArray.tab[i]->x) , ( solid->position.y + solid->verticesArray.tab[i]->y ) );
	}
	glEnd();
	
	
	//draw_circle(solid->position, solid->radius);
}



//////////////////////////////////////////////////////////////////////////////////////////
//	MISE À JOUR DE LA PROCHAINE POSITION (pour la détection de collision)
//////////////////////////////////////////////////////////////////////////////////////////
void solid_updateNextPosition( Solid *solid, int gap )
{	
	solid->nextPosition.x = solid->position.x + (( solid->speed.x * gap )/1000) ;
	solid->nextPosition.y = solid->position.y + (( solid->speed.y * gap )/1000) ;
	//solid->position.z = solid->position.z + solid->speed.z ;
}


/////////////////////////////////////////////////////////////////////////////////////////
//	MISE À JOUR DE LA POSITION D'UN SOLID
/////////////////////////////////////////////////////////////////////////////////////////
void solid_updatePosition( Solid *solid, int gap )
{		
	solid->position.x = solid->position.x + (( solid->speed.x * gap )/1000) ;
	solid->position.y = solid->position.y + (( solid->speed.y * gap )/1000) ;
	//solid->position.z = solid->position.z + solid->speed.z ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//	MISE À JOUR DE LA VITESSE D'UN SOLID
//////////////////////////////////////////////////////////////////////////////////////////
void solid_updateSpeed( Solid *solid, int gap )
{	
	solid->speed.x = solid->speed.x + (( solid->acceleration.x * gap )/1000) ;
	solid->speed.y = solid->speed.y + (( solid->acceleration.y * gap )/1000) ;
	//solid->speed.z = solid->speed.z + (( solid->acceleration.z * gap )/1000) ;	
}



//-------------------------------------------------------------
//	Calcul de l'enveloppe rectangulaire d'un solid
//-------------------------------------------------------------
float* solid_getExternalAura( Solid *solid )
{
	float max_y = 0;
	float max_x = 0;
	float min_y = 0;
	float min_x = 0;
	
	int i = 0;
	float *result = malloc( sizeof(float) * 4 );
	
	
	max_y = ( solid->position.y ) + ( solid->verticesArray.tab[0]->y );
	max_x = ( solid->position.x ) + ( solid->verticesArray.tab[0]->x );
	min_y = ( solid->position.y ) + ( solid->verticesArray.tab[0]->y );
	min_x = ( solid->position.x ) + ( solid->verticesArray.tab[0]->x );
	
	
	for ( i=1 ; i < solid->verticesArray.size ; i++)
	{
		if ( ((solid->position.y)+(solid->verticesArray.tab[i]->y)) > max_y)
		{
			max_y = ((solid->position.y)+(solid->verticesArray.tab[i]->y));
		}
		
		
		if ( ((solid->position.x)+(solid->verticesArray.tab[i]->x)) > max_x)
		{
			max_x = ((solid->position.x)+(solid->verticesArray.tab[i]->x));
		}
		
		
		if ( ((solid->position.y)+(solid->verticesArray.tab[i]->y)) < min_y)
		{
			min_y = ((solid->position.y)+(solid->verticesArray.tab[i]->y));
		}
		
		
		if ( ((solid->position.x)+(solid->verticesArray.tab[i]->x)) < min_x)
		{
			min_x = ((solid->position.x)+(solid->verticesArray.tab[i]->x));
		}
	}
	
	/*
	printf("%f\n", max_y );
	printf("%f\n", max_x );
	printf("%f\n", min_y );
	printf("%f\n", min_x );
	printf("----------------\n");
	*/
	 
	 
	result[0] = max_y;
	result[1] = max_x;
	result[2] = min_y;
	result[3] = min_x;

	return result;
}









