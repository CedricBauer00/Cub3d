/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:02:57 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/15 13:05:48 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Here we have the first part of the calculations made for the ray.
	we have the ray as a straight line and since we know the tile size and 
	where it's pointed to, using cos and sin functions we can determine the
	movements of our character.(sin is set as minus because it grows downwards)

	Then we use the fabs function to make the number we want to assign positive
	if it's negative.
	We need to calculate delta distances because depending on
	the angle of the ray, the amount of movement in the x and y directions changes
	and if it's 0 we set the deltaDirX/Y to 1e30(infinity) because otherwise we would try to
	divide a number by 0 which is not possible.

	We add 4 to the coordinants because of how i draw stuff but i will be changing that.
	Then we divide them by 64 because for the moment our tile size is 64.
	For example the map is 512 x 512 long because it was built pixel by pixel,
	if x is 134 we know that x is actually 2, which helps us see where we are on the map by using something like map[y][x].

	the if statements down at the bottom in the ray_initializer2 function are for the directions we need to follow.
	sideDistX/Y are there to determine how much we need to move in the y and x axis.
*/

void	ray_initializer(t_player *p, double angle)
{
	p->rayDirX = cos(angle);
	p->rayDirY = -sin(angle);
	if (p->rayDirX == 0.0)
		p->deltaDistX = 1e30;
	else
		p->deltaDistX = fabs(1.0 / p->rayDirX);
	if (p->rayDirY == 0.0)
		p->deltaDistY = 1e30;
	else
		p->deltaDistY = fabs(1.0 / p->rayDirY);
	p->posX = (p->x) / (double)TS;
	p->posY = (p->y) / (double)TS;
	p->mapX = (int)p->posX;
	p->mapY = (int)p->posY;
    ray_initializer_2(p);
}

void    ray_initializer_2(t_player *p)
{
    if (p->rayDirX > 0)
	{
		p->stepX = 1;
		p->sideDistX = (p->mapX + 1 - p->posX) * p->deltaDistX;
	}
	else
	{
		p->stepX = -1;
		p->sideDistX = (p->posX - p->mapX) * p->deltaDistX;
	}
	if (p->rayDirY > 0)
	{
		p->stepY = 1;
		p->sideDistY = (p->mapY + 1 - p->posY) * p->deltaDistY;
	}
	else
	{
		p->stepY = -1;
		p->sideDistY = (p->posY - p->mapY) * p->deltaDistY;
	}
}

void	draw_ray_init(t_player *p, t_ray *r, double angle, int check)
{
	r->angleDiff = angle - p->angle;
	r->angleDiff = normalised_angle(r->angleDiff);
	if (r->angleDiff > PI)
		r->angleDiff -= 2.0 * PI;
	if (check == 0)
		r->rawDist = (p->mapX - p->posX + (1.0 - p->stepX) * 0.5) / p->rayDirX;
	else
		r->rawDist = (p->mapY - p->posY + (1.0 - p->stepY) * 0.5) / p->rayDirY;
	r->wallDist = r->rawDist * cos(r->angleDiff);
	if (r->wallDist < 1e-6)
		r->wallDist = 1e-6;
}
