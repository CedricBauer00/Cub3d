/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:32:36 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/27 16:42:07 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	texture_colour(mlx_texture_t *img, int x, int y, int check)
{
	int		i;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	i = (y * img->width + x) * img->bytes_per_pixel;
	r = img->pixels[i];
	g = img->pixels[i + 1];
	b = img->pixels[i + 2];
	a = img->pixels[i + 3];
	if (check == 0)
		return (shade_colour(r << 24 | g << 16 | b << 8 | a));
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	shade_colour(uint32_t colour)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = (colour >> 24) / 2;
	g = ((colour >> 16) % 256) / 2;
	b = ((colour >> 8) % 256) / 2;
	a = colour % 256;
	return (r << 24 | g << 16 | b << 8 | a);
}

mlx_texture_t	*check_sides(t_game *g, t_tex *t, int side, t_ray ray)
{
	int	x;
	int	y;

	(void)ray;
	x = g->player->map_x;
	y = g->player->map_y;
	if (g->map[y][x] == '2')
		return (t->door);
	if (side == 0)
	{
		if (g->player->ray_dir_x > 0)
			return (t->ea);
		else
			return (t->we);
	}
	else
	{
		if (g->player->ray_dir_y > 0)
			return (t->so);
		else
			return (t->no);
	}
}

static void	draw_vertical_init(t_ray r, int check, t_game *g, t_tex *t)
{
	if (check == 0)
		t->wall_x = r.hit_y;
	else
		t->wall_x = r.hit_x;
	t->wall_x -= floor(t->wall_x);
	t->tex_x = (int)(t->wall_x * (double)g->tex->no->width);
	if ((check == 0 && g->player->ray_dir_x > 0)
		|| (check == 1 && g->player->ray_dir_y < 0))
		t->tex_x = g->tex->no->width - t->tex_x - 1;
	t->step = 1.0 * g->tex->no->height / r.line_h;
	t->tex_pos = (r.draw_s - HEIGHT / 2 + r.line_h / 2) * t->step;
}

void	draw_vertical(t_game *g, t_ray r, int check, int ray_i)
{
	int				i;
	int				j;
	t_tex			*t;
	uint32_t		colour;
	mlx_texture_t	*tex;

	i = 0;
	j = WIDTH - ray_i;
	t = g->tex;
	tex = check_sides(g, t, check, r);
	if (j >= WIDTH)
		return ;
	draw_vertical_init(r, check, g, t);
	while (i < r.draw_s)
		mlx_put_pixel(g->player->image, j, i++, g->tex->sky);
	while (i < r.draw_e)
	{
		t->tex_y = (int)t->tex_pos % tex->height;
		t->tex_pos += t->step;
		colour = texture_colour(tex, t->tex_x, t->tex_y, check);
		mlx_put_pixel(g->player->image, j, i, colour);
		i++;
	}
	while (i < HEIGHT)
		mlx_put_pixel(g->player->image, j, i++, g->tex->floor);
}
