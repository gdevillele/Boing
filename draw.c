/*
 *  draw.c
 *  Boing
 *
 *  Created by Gaëtan de Villèle on 19/01/11.
 *  Copyright 2011 EPSI. All rights reserved.
 *
 */

#include "draw.h"




void draw_circle( Vector position, float radius )
{
	int		i				= 0;
	float	a				= (   M_PI / 30 );
	float	da				= ( ( M_PI * 2.00 ) / 30 );
	
	glBegin(GL_LINE_LOOP);			
	for( i = 0 ; i < 30 ; i++ )
	{
		a += da;
		glVertex2d( ( position.x+(cos(a) * radius) ) , position.y+( (sin(a) * radius) ) );
	}	
	glEnd();
}
