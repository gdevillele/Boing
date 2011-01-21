/////////////////////////////////////////////////////////////
///
///		@name	: main.c
///		@author : Yann & Ga‘tan
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
    SDL_WM_SetCaption("Boing - Physic Engine",NULL);
    SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport ( 0, 0, 1024, 768);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-512,512,-384,384);
	glLineWidth(2.0);
	physicEngine_setWindowSize( -512, 512, -384, 384 );

	
	// GŽnŽration de la map
	Vector position;
	position.x = ( - 0 );
	position.y = (- 370);
	position.z = 0;
	Vector speed;
	speed.x = 0;
	speed.y = 0;
	speed.z = 0;
	Vector acceleration;
	acceleration.x = 0;
	acceleration.y = 0;
	acceleration.z = 0;
	physicEngine_create_rect( position, speed, acceleration, (float) 1024, (float) 28, 1 );
	
	
	//	MAIN LOOP
    while (continuer)
    {
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
						speed.x = 0;
						speed.y = 0;
						speed.z = 0;
						Vector acceleration;
						acceleration.x = 0;
						acceleration.y = -500;
						acceleration.z = 0;
						physicEngine_create_rect( position, speed, acceleration, (float) 30, (float) 30, 0 );
					}
					else if ( event.button.button == SDL_BUTTON_RIGHT )
					{
						Vector position;
						position.x = ( event.button.x - 512 );
						position.y = -( event.button.y - 384 );
						position.z = 0;
						Vector speed;
						speed.x = 200;
						speed.y = 500;
						speed.z = 0;
						Vector acceleration;
						acceleration.x = 0;
						acceleration.y = -500;
						acceleration.z = 0;
						//physicEngine_create_polygon( position, speed, acceleration, 5, (float) 150, 1 );
						physicEngine_create_rect( position, speed, acceleration, (float) 50, (float) 50, 0 );
					}
					break;
				case SDL_MOUSEMOTION:
					if(1 == 1)
					//if( event.motion.x > 0 && event.motion.x < 1023)
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
						//physicEngine_create_rect( position, speed, acceleration, (float) 20, (float) 5, 0 );
						//physicEngine_create_polygon( position, speed, acceleration, 3, (float) 10, 0 );

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
		
		// --- 2 --- : Žlimination des solids hors champ
		physicEngine_removeUselessSolids();
		
		// --- 3 --- : detection des collision
		physicEngine_detectCollisions();
		
		// --- 4 --- : calcul d'une rŽponse aux collisions
			// sera dans la meme boucle que la detection de collisions:
			//
		
		// --- 5 --- : mise ˆ jour de l'Žtat des solides
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
		
    } // main loop end
	
	
	
	
	//-------------------------------------
	// DŽsallocation du tableau de solids
	//-------------------------------------
	physicEngine_free();
	
    SDL_Quit();
	
    return 0;
} // --------------------- FIN DU MAIN --------------------------































