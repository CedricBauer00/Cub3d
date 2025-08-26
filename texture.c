/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:32:36 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/26 13:58:07 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	texture_colour(mlx_texture_t *img, int x, int y)
{
	int	i;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	i = (y * img->width + x) * img->bytes_per_pixel;
	r = img->pixels[i];
	g = img->pixels[i + 1];
	b = img->pixels[i + 2];
	a = img->pixels[i + 3];
	
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	shade_colour(uint32_t colour)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = (colour >> 24) / 2;
	g = (colour >> 16) / 2;
	b = (colour >> 8) / 2;
	a = colour % 256;

	return (r << 24 | g << 16 | b << 8 | a);
}

mlx_texture_t	*check_sides(t_game *g, t_tex *t, int side)
{
	if (side == 0)
	{
		if (g->player->rayDirX > 0)
			return (t->ea);
		else
			return (t->we);
	}
	else
	{
		if (g->player->rayDirY > 0)
			return (t->so);
		else
			return (t->no);
	}
}

static void	draw_vertical_init(t_ray r, int check, t_game *g, t_tex *t)
{
	if (check == 0)
		t->wallX = r.hitY;
	else
		t->wallX = r.hitX;
	t->wallX -= floor(t->wallX);
	t->texX = (int)(t->wallX * (double)g->tex->no->width);
	if ((check == 0 && g->player->rayDirX > 0) || (check == 1 && g->player->rayDirY < 0))
		t->texX = g->tex->no->width - t->texX - 1;
	t->step = 1.0 * g->tex->no->height / r.lineH;
	t->texPos = (r.drawS - HEIGHT / 2 + r.lineH / 2) * t->step;
}

void	draw_vertical(t_game *g, t_ray r, int check, int ray_i)
{
	int	i;
	int	j;
	t_tex	*t;
	uint32_t	colour;
	mlx_texture_t	*tex;

	i = 0;
	j = WIDTH - ray_i;
	t = g->tex;
	tex = check_sides(g, t, check);
	if (j >= WIDTH)
		return;
	draw_vertical_init(r, check, g, t);
	while (i < r.drawS)
		mlx_put_pixel(g->player->image, j, i++, 0x87CEEBFF);
	while (i < r.drawE)
	{
		t->texY = (int)t->texPos % tex->height;
		t->texPos += t->step;
		colour = texture_colour(tex, t->texX, t->texY);
		// if (check == 0)
		// 	colour = shade_colour(colour);
		mlx_put_pixel(g->player->image, j, i, colour);
		i++;
	}
	while (i < HEIGHT)
		mlx_put_pixel(g->player->image, j, i++, 0x333333FF);
}
