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


///////////////////////////////////////////////////////////////////////////////////////////////
//
//	VARIABLES
//
///////////////////////////////////////////////////////////////////////////////////////////////

	// Tableau des Solids
	//------------------------------------------------------------
	int		sizeTabSolids	= 0;
	Solid*	*tabSolids		= NULL;

	// Window size
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;






///////////////////////////////////////////////////////////////////////////////////////////////
//
//	FUNCTIONS
//
///////////////////////////////////////////////////////////////////////////////////////////////

// Définition des dimensions de la fenetre
//------------------------------------------------------------

void physicEngine_setWindowSize( int win_x_min, int win_x_max, int win_y_min, int win_y_max )
{
	x_min = win_x_min;
	x_max = win_x_max;
	y_min = win_y_min;
	y_max = win_y_max;
}











//----------------------------------------------------------------------------------------------
//	PHYSIC ENGINE
//----------------------------------------------------------------------------------------------
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
	int j;
	int k;
	for ( i=0 ; i<sizeTabSolids ; i++ )
	{
		for ( j=(i+1) ; j < sizeTabSolids ; j++)	// ne pas comparer a -> b ET b->a (optimisation)
		{
				//k = 0;
				//k = 
				physicEngine_detectExternCollision( tabSolids[i], tabSolids[j] );
		}
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







//----------------------------------------------------------------------------------------------
//	CREATE SOLID - RECTANGLE		( TODO : rotation lors de la creation ? )
//----------------------------------------------------------------------------------------------
void physicEngine_create_rect( Vector position, Vector speed, Vector acceleration, float width, float height, int staticSolid )
{
	// Constantes
	const int sides				= 4;
	
	// Variables
	int		i					= 0;
	float	a					= (float) 0;
	float	ia					= (float) 0;	
	float	half_width			= ( width  / (float) 2 );
	float	half_height			= ( height / (float) 2 );
	float	rotation			= (float) 0; 
	
	// Code
	Solid *solid				= malloc( sizeof(Solid) * 1);
	solid->position				= position;
	solid->speed				= speed;
	solid->acceleration			= acceleration;
	solid->staticSolid			= staticSolid;
	solid->color[0]				= rand()%255;
	solid->color[1]				= rand()%255;
	solid->color[2]				= rand()%255;
	// On conserve le radius pour connaitre le cercle circonscrit
	solid->radius				= sqrt( (double)( half_width * half_width + half_height * half_height ) );
	solid->verticesArray		= tabVector_create();
	
	ia							= acos( ( half_width / solid->radius ) );
	a							= ia;
	// la rotation est en radians ( 2PI = 360° )
	//float rotation = (float)(rand()%(624))/100;

	for( i = 0 ; i < sides ; i++ ) // Pour i de 0 à 3
	{
		// on crée le sommet
		Vector *pos = malloc( sizeof( Vector ) );
		pos->x = ( (cos(a + rotation) * solid->radius) );
		pos->y = ( (sin(a + rotation) * solid->radius) );
		tabVector_add( &solid->verticesArray, pos );
				
		// ensuite on passe à l'angle suivant
		if( (i%2) == 0)  // si i est pair (0,2)
		{
			a += ( M_PI - ( (float) 2 * ia ) );
		}
		else
		{
			a += ( (float) 2 * ia );
		}
	}	
	
	sizeTabSolids++;
	if(sizeTabSolids <= 1)
		tabSolids = malloc( sizeTabSolids * sizeof(Solid*) );
	else
		tabSolids = realloc( tabSolids, sizeTabSolids * sizeof(Solid*) );
	tabSolids[sizeTabSolids-1] = solid;
}


//----------------------------------------------------------------------------------------------
//	CREATE SOLID : REGULAR POLYGON
//----------------------------------------------------------------------------------------------
void physicEngine_create_polygon( Vector position, Vector speed, Vector acceleration, int sides, float radius, int staticSolid )
{
	// Variables
	//------------------------------------------------------------
	
	int		i				= 0;
	float	a				= (   M_PI / (float) sides );
	float	da				= ( ( M_PI * 2.00 ) / (float) sides );
	float	rotation		= (float) 0; 
	
	
	// Code
	//------------------------------------------------------------
	
	Solid *solid				= malloc( sizeof(Solid) * 1);
	solid->position				= position;
	solid->speed				= speed;
	solid->acceleration			= acceleration;
	solid->staticSolid			= staticSolid;
	solid->color[0]				= rand()%255;
	solid->color[1]				= rand()%255;
	solid->color[2]				= rand()%255;
	solid->radius				= radius;
	solid->verticesArray		= tabVector_create();
	
	// la rotation est en radians ( 2PI = 360° )
	rotation = (float)(rand()%(624))/100;
	
	
	for( i = 0 ; i < sides ; i++ ) // Pour i de 0 à n-1
	{
		a += da;
		// on crée le sommet
		Vector *pos = malloc( sizeof( Vector ) );
		pos->x = ( (cos(a + rotation) * solid->radius) );
		pos->y = ( (sin(a + rotation) * solid->radius) );
		tabVector_add( &solid->verticesArray, pos );
	}	
	
	sizeTabSolids++;
	if(sizeTabSolids <= 1)
		tabSolids = malloc( sizeTabSolids * sizeof(Solid*) );
	else
		tabSolids = realloc( tabSolids, sizeTabSolids * sizeof(Solid*) );
	tabSolids[sizeTabSolids-1] = solid;
}



//--------------------------------------------------------------------------
// Supprimer un solid
//--------------------------------------------------------------------------
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




//--------------------------------------------------------------------------
// Libération de la mémoire
//--------------------------------------------------------------------------
void physicEngine_free()
{
	int i = 0;
	for (i=0; i<sizeTabSolids; i++)
	{
		free(tabSolids[i]);
	}
	free(tabSolids);
}








//--------------------------------------------------------------------------
//	DETECTION DE COLLISION DES ENVELOPPES RECTANGULAIRES
//--------------------------------------------------------------------------
int physicEngine_detectExternCollision( Solid* s1, Solid* s2 )
{
	float	*tabS1		= NULL; // dimension 4
	float	*tabS2		= NULL; // dimension 4
	int		collision	= 0;
	
	
	tabS1 = solid_getExternalAura(s1);
	tabS2 = solid_getExternalAura(s2);
	

	
	if(   ((tabS2[3] <= tabS1[1]) && (tabS1[1] <= tabS2[1])  ||  (tabS1[3] <= tabS2[1]) && (tabS2[1] <= tabS1[1])) && ((tabS2[2] <= tabS1[0]) && (tabS1[0] <= tabS2[0])  ||  (tabS1[2] <= tabS2[0]) && (tabS2[0] <= tabS1[0]))   )
	{
		//s1->staticSolid = 1;
		//s2->staticSolid = 1;
		collision = 1;
		
		
		
		
		
		if( s1->staticSolid == 1 )
		{
			s2->speed.y *= (-1);
		}
		else if( s2->staticSolid == 1 )
		{
			s1->speed.y *= (-1);
		}
		else
		{
			s1->staticSolid = 1;
			s2->staticSolid = 1;
		}
		
		
		
		
		
		
	}
	
	// REPONSE A LA COLLISION
	//
	// 1) Un des deux solides est fixe -> toute l'energie est pour le 2eme
	// 2) Les solides sont floattants  -> gestion du poids (poids identique pour commencer)
	
	

	
	
	
	
	
	// Return 1 if collision
	return collision;
}




















//--------------------------------------------------------------------------
//	DETECTION DE COLLISION DES ENVELOPPES RECTANGULAIRES
//--------------------------------------------------------------------------
/*
int physicEngine_detectExternCollision( Solid* s1, Solid* s2 )
{
	float *tabS1 = NULL; // dimension 4
	float *tabS2 = NULL; // dimension 4
	
	
	tabS1 = solid_getExternalAura(s1);
	tabS2 = solid_getExternalAura(s2);
	
	
	
	if(   ((tabS2[3] <= tabS1[1]) && (tabS1[1] <= tabS2[1])  ||  (tabS1[3] <= tabS2[1]) && (tabS2[1] <= tabS1[1])) && ((tabS2[2] <= tabS1[0]) && (tabS1[0] <= tabS2[0])  ||  (tabS1[2] <= tabS2[0]) && (tabS2[0] <= tabS1[0]))   )
	{
		s1->staticSolid = 1;
		s2->staticSolid = 1;
	}
	
	// Return 1 if collision
	return 1;
}
*/








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///	Detection de collision des enveloppes Circulaires
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int physicEngine_detectExternCollision( Solid* s1, Solid* s2 )
{
	//int		resultat = 0;
	Vector	v				= Vector_create();
	float	norme_center	= (float)0;
	float	somme_radius	= (float)0;
	
	
	// On calcul la distance entre les 2 centres des solides
	v				= vector_soustraction( s1->position, s2->position);
	norme_center	= vector_norm( v );
	somme_radius	= s1->radius + s2->radius;
	
	
	//printf("%f | %f  \n", v.x, v.y);
	//printf("%f\n", norme_center);
	//printf("%f\n", somme_radius);
	
	if (norme_center > somme_radius )
	{
		// pas de collision des cercles
	}
	else
	{
		//s1->staticSolid = 1;
		//s2->staticSolid = 1;
	}
	
	return 1;
}
*/



////////////////////////////////////////////////////////////////////////////////////////////////////////
//	BROUILLON : detection de collision des enveloppes rectangulaires
///////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 //COLLISION
 // X
 if(      (tabS2[3] <= tabS1[1]) && (tabS1[1] <= tabS2[1])  ||  (tabS1[3] <= tabS2[1]) && (tabS2[1] <= tabS1[1])      )
 {
 s1->staticSolid = 1;
 s2->staticSolid = 1;
 }
 
 // Y
 if(      (tabS2[2] <= tabS1[0]) && (tabS1[0] <= tabS2[0])  ||  (tabS1[2] <= tabS2[0]) && (tabS2[0] <= tabS1[0])      )
 {
 s1->staticSolid = 1;
 s2->staticSolid = 1;
 }
 */


































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





