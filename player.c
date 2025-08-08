/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:53 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/08 15:19:02 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delete_image(mlx_image_t *image)
{
	ft_memset(image->pixels, 0, image->width * image->height * sizeof(uint32_t));
}

void	draw_player_ex(t_game *game, mlx_image_t *image)
{
	int i;
    int j;
    int d_x;
    int d_y;
	int	p_x;
	int	p_y;

    i = 0;
    j = 0;
    d_x = game->player->x;
    d_y = game->player->y;
	delete_image(image);
	while (i < 20)
	{
		p_x = d_x + 4 + (int)round(cos(game->player->angle) * i);
		p_y = d_y + 4 - (int)round(sin(game->player->angle) * i);
		mlx_put_pixel(image, p_x, p_y, 0xFFFF00FF);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_put_pixel(image, d_x + i, d_y + j, 0xFFFF00FF);
			j++;
		}
		i++;
	}
	draw_ray2(game, image);
}

void	draw_ray2(t_game *game, mlx_image_t *image)
{
	double	dx = cos(game->player->angle);
	double	dy = sin(game->player->angle);
	double	m = tan(game->player->angle);
	int		mapX = game->player->x;
	int		mapY = game->player->y;
	double	x = (double)game->player->x;
	double	y = (double)game->player->y;
	double	sideDX;
	double	sideDY;
	double	Fx;
	double	Fy;
	double	deltaX;
	double	deltaY;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		l = 0;
	int		Sx;
	int		Sy;

	if (dx >= 0)
		Sx = 1;
	else
		Sx = -1;
	dy *= -1;
	if (dy >= 0)
		Sy = 1;
	else
		Sy = -1;
	x /= 32;
	y /= 32;
	Fx = floor(x);
	Fy = floor(y);
	// x /= 32;
	// y /= 32;
	if (dx == 0)
		deltaX = INFINITY;
	else
		deltaX = sqrt(1 + ((dy / dx) * (dy / dx)));
	if (dy == 0)
		deltaY = INFINITY;
	else
		deltaY = sqrt(1 + ((dx / dy) * (dx / dy)));
	// if (dx >= 0)
	// 	sideDX = (Fx + 1.0 - x) * deltaX;
	// else
	// 	sideDX = (x - Fx) * deltaX;
	// if (dy >= 0)
	// 	sideDY = (Fy + 1.0 - y) * deltaY;
	// else
	// 	sideDY = (y - Fy) * deltaY;
	// Fx = x - floor(x);
	// Fy = y - floor(y);
	while (1)
	{
		// Fx = x - floor(x);
		// Fy = y - floor(y);
		// if (Fx < Fy)
		// {
		// 	x += (Sx * deltaX);
		// }
		// else
		// {
		// 	y += (Sy * deltaY);
		// }
		// i = floor(x);
		// j = floor(y);
		mlx_put_pixel(image, mapX, mapY, 0xFF0000FF);
		if (dx >= 0)
			sideDX = (Fx + 1.0 - mapX) * deltaX;
		else
			sideDX = (mapX - Fx) * deltaX;
		if (dy >= 0)
			sideDY = (Fy + 1.0 - mapY) * deltaY;
		else
			sideDY = (mapY - Fy) * deltaY;
		if (sideDX < sideDY)
		{
			sideDX += deltaX;
			mapX += Sx;
		}
		else
		{
			sideDY += deltaY;
			mapY += Sy;
		}
		// printf("x = %f, y = %f\n", x, y);
		printf("i = %d, j = %d\n", mapX, mapY);
		if (game->map[mapY / 32][mapX / 32] == 1)
			break ;
		// mlx_put_pixel(image, mapX, mapY, 0xFF0000FF);
	}
	// x *= 32;
	// y *= 32;
	// // printf("x = %f, y = %f\n", x, y);
	// while (k < y)
	// {
	// 	k++;
	// }
}

void	draw_ray1(t_game *game, mlx_image_t *image)
{
	double	theta = game->player->angle;
	double	dx = cos(theta);
	double	dy = sin(theta);
	double	m = tan(theta);
	double	absDX;
	double	absDY;
	double	j = 0;
	double	i = 0;
	int		s;
	int		stepX;
	int		stepY;
	double	x = (double)game->player->x;
	double	y = (double)game->player->y;

	if (dx >= 0)
		stepX = 1;
	else
		stepX = -1;
	dy *= -1;
	if (dy >= 0)
		stepY = 1;
	else
		stepY = -1;
	x /= 32;
	y /= 32;
	// while (1)
	// {
	// 	i = x - floor(x);
	// 	j = y - floor(y);
	// 	printf("RAY: x = %d, y = %d, angle = %f\n", x, y, game->player->angle);
	// 	while (i > j)
	// 	{
	// 		i += 1;
	// 	}
	// 	while (j > i)
	// 	{
	// 		j += 1;
	// 	}
	// }
	printf("RAY: x = %f, y = %f, angle = %f\n", x, y, game->player->angle);
	// x /= 32;
	// y /= 32;
	i = x - floor(x);
	j = y - floor(y);
	printf("RAY: x = %f, y = %f, angle = %f\n", i, j, game->player->angle);
}

// void	draw_ray(t_game *game, mlx_image_t *image)
// {
// 	int	i;
// 	int	j;
// 	int	dx;
// 	int	dy;
// 	int	ax;
// 	int	ay;
	
// 	i = 0;
// 	j = 0;
// 	ax = (int)round(cos(game->player->angle));
// 	ay = (int)round(cos(game->player->angle));
// 	dx = game->player->x;
// 	dy = game->player->x;
// 	dx += ax;
// 	dy += ay;
// 	while (1)
// 	{
// 		if (game->map[dy / 32][dx / 32] == 1)
// 		{
// 			break ;
// 		}
// 	}
// }

// void	draw_player_sides(t_game *game, mlx_image_t *image)
// {
// 	int i;
//     int j;
//     int d_x;
//     int d_y;

//     i = 0;
//     j = 0;
//     d_x = game->player->x;
//     d_y = game->player->y;
// 	delete_image(image);
// 	while (i < 20)
// 	{
// 		// printf("1\n");
// 		d_x = game->player->x;
// 		d_y = game->player->y;
// 		if (game->player->dir == LEFT)
// 			d_x -= i;
// 		if (game->player->dir == RIGHT)
// 			d_x += i;
// 		if (i < 20)
// 		{
// 			j = 0;
// 			// printf("3\n");
// 			while (j < 8)
// 			{
// 				if (game->player->dir == LEFT)
// 				{
// 					d_y += j;
// 				}
// 				if (game->player->dir == RIGHT)
// 				{
// 					d_y += j;
// 				}
// 				// printf("before pixel\n");
// 				if (j > 2 && j < 6)
// 					mlx_put_pixel(game->player->image, d_x, d_y, 0xFFFF00FF);
// 				// printf("after pixel\n");
// 				d_y = game->player->y;
// 				j++;
// 			}
// 			// printf("4\n");
// 		}
// 		d_x = game->player->x;
// 		j = 0;
// 		while (j < 8 && i < 8)
// 		{
// 			mlx_put_pixel(image, d_x + i, d_y + j, 0x40E0D0);
// 			j++;
// 		}
// 		i++;
// 		// printf("5\n");
// 	}
// }

// void	draw_player_updown(t_game *game, mlx_image_t *image)
// {
//     int i;
//     int j;
// 	int	x;
// 	int	y;
//     int d_x;
//     int d_y;

//     i = 0;
//     j = 0;
//     d_x = game->player->x;
//     d_y = game->player->y;
// 	x = game->player->inst->x;
// 	y = game->player->inst->y;
// 	delete_image(image);
// 	while (i < 8)
// 	{
// 		// printf("1\n");
// 		d_x = game->player->x;
// 		d_y = game->player->y;
// 		if (game->player->dir == UP)
// 			d_x += i;
// 		if (game->player->dir == DOWN)
// 			d_x += i;
// 		if (i == 3 || i == 4 || i == 5)
// 		{
// 			// // printf("2\n");
// 			j = 0;
// 			// printf("3\n");
// 			while (j < 20)
// 			{
// 				if (game->player->dir == UP)
// 				{
// 					d_y -= j;
// 				}
// 				if (game->player->dir == DOWN)
// 				{
// 					d_y += j;
// 				}
// 				// printf("before pixel\n");
// 				mlx_put_pixel(game->player->image, d_x, d_y, 0xFFFF00FF);
// 				// printf("after pixel\n");
// 				d_y = game->player->y;
// 				j++;
// 			}
// 			// printf("4\n");
// 		}
// 		j = 0;
// 		while (j < 8)
// 		{
// 			mlx_put_pixel(image, d_x, d_y + j, 0x40E0D0);
// 			j++;
// 		}
// 		i++;
// 		// printf("5\n");
// 	}
// }
