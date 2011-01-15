/////////////////////////////////////////////////////////////
///
///		@name	: main.c
///		@author : Yann & Gaëtan
///		@date	: 9/11/2010
///
/////////////////////////////////////////////////////////////


#include "main.h"



int main(int argc, char *argv[])
{
	//	Variables
	//-----------------------------------------
	SDL_Event	event;
	int			continuer		= 1;
	
	int			gap				= 0;
	//int			fps				= 60;
	Uint32		actualTime		= 0;
	
	
	
	
	
	
	///	Fonctions
	//-----------------------------------------
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Physique Engine :D",NULL);
    SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport ( 0, 0, 1024, 768);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-512,512,-384,384);
	
	
	//	MAIN LOOP
    while (continuer)
    {
		/*
		 Vector position;
		 position.x = ( ((rand()%1024)-512) );
		 position.y = ( 384 );
		 position.z = 0;
		 Vector speed;
		 speed.x = (rand()%300)-150;
		 speed.y = 0;
		 speed.z = 0;
		 Vector acceleration;
		 acceleration.x = 0;
		 acceleration.y = -200;
		 acceleration.z = 0;
		 physicEngine_add_solid( position, speed, acceleration, 7, (double) 5 );
		 */
		
		//	Gestion des Events
		//----------------------------------------
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					continuer = 0;
					break;
					
				case SDL_MOUSEBUTTONUP:
					if( event.button.button == SDL_BUTTON_LEFT )
					{
						
						Vector position;
						position.x = ( event.button.x - 512 );
						position.y = -( event.button.y - 384 );
						position.z = 0;
						Vector speed;
						speed.x = 150;
						speed.y = 500;
						speed.z = 0;
						Vector acceleration;
						acceleration.x = 0;
						acceleration.y = -1000;
						acceleration.z = 0;
						physicEngine_add_solid( position, speed, acceleration, 3, (double) 100, 1 );
					}
					break;
				case SDL_MOUSEMOTION:
					if(1)
					{
						Vector position;
						position.x = ( event.motion.x - 512 );
						position.y = -( event.motion.y - 384 );
						position.z = 0;
						Vector speed;
						speed.x = (rand()%300)-150;
						speed.y = (rand()%300)-150;
						speed.z = 0;
						Vector acceleration;
						acceleration.x = 0;
						acceleration.y = -500;
						acceleration.z = 0;
						physicEngine_add_solid( position, speed, acceleration, 7, (double) 5, 0 );
					}
					break;
					
				default :
					break;
			}
		}
		
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////////
		///	Moteur physique + controle du framerate
		////////////////////////////////////////////////////////////////////////////////////////////////////
		gap = ( SDL_GetTicks() - actualTime );
		
		// Moteur Physique
		//--------------------------------------------------------------------------
		// --- 1 --- : calcul des nouvelles positions
		physicEngine_computeNextPositions( gap );
		
		// --- 2 --- : élimination des solids hors champ
		
		// --- 3 --- : detection des collision
		
		// --- 4 --- : calcul d'une réponse aux collisions
		
		// --- 5 --- : mise à jour de l'état des solides
		physicEngine_updateSolidsState( gap );
		
		// --- 6 --- : affichage des solids
		// On efface la scene avant de redessiner
		glClear(GL_COLOR_BUFFER_BIT);
		// On demande au moteur d'afficher les solids
		physicEngine_display();
		//--------------------------------------------------------------------------
		
		
		// On met a jour la variable actualTime.
		actualTime = SDL_GetTicks();
		SDL_Delay(5);
		glFlush();
		SDL_GL_SwapBuffers();
		
    } // fin de la boucle principale
	
	
	
	
	//-------------------------------------
	// Désallocation du tableau de solids
	//-------------------------------------
	physicEngine_free();
	
    SDL_Quit();
	
    return 0;
} // --------------------- FIN DU MAIN --------------------------































