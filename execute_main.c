/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:28:17 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/26 13:58:20 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_uppercase_hex(unsigned int nbr, int i, int check)
{
	unsigned int	copy;
	char			number[9];

	copy = nbr;
	while (copy > 0)
	{
		if (copy % 16 >= 10)
			number[i++] = copy % 16 + 'A' - 10;
		else
			number[i++] = copy % 16 + 48;
		copy /= 16;
	}
	number[i] = '\0';
	while (i > 0)
	{
		check = write(1, &number[--i], 1);
	}
}

void	init_texture(t_configs *d, t_game *g)
{
	g->tex->no = mlx_load_png("pngs/wall_1.png");
	g->tex->so = mlx_load_png("pngs/wall_2.png");
	g->tex->we = mlx_load_png("pngs/wall_3.png");
	g->tex->ea = mlx_load_png("pngs/wall_4.png");

	g->tex->noT = mlx_texture_to_image(g->mlx, g->tex->no);
	g->tex->soT = mlx_texture_to_image(g->mlx, g->tex->so);
	g->tex->weT = mlx_texture_to_image(g->mlx, g->tex->we);
	g->tex->eaT = mlx_texture_to_image(g->mlx, g->tex->ea);
}

int execute_main(t_configs *data)
{
	t_game	*game;

	game = gc_malloc(sizeof(t_game), EXEC);
	if (!game)
		return (0);
	game->player = gc_malloc(sizeof(t_player), EXEC);
	if (!game->player)
		return (0);
	game->tex = gc_malloc(sizeof(t_tex), EXEC);
	if (!game->tex)
		return (0);
	game->ray = gc_malloc(sizeof(t_ray), EXEC);
	if (!game->ray)
		return (0);
	game->mlx = mlx_init(WIDTH, HEIGHT, "game", true);
	if (!game->mlx)
		return (0);
	init_texture(data, game);
	game->sky = data->textures->c_clr;
	game->floor = data->textures->f_clr;
	initialize(data->map_info, game);
	game->player->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->player->minimap = mlx_new_image(game->mlx, WIDTH / 3, HEIGHT / 3);
	draw_player(game, game->player->image);
	draw_minimap(game, game->player->minimap, 0, -1);
	mlx_image_to_window(game->mlx, game->player->image, 0, 0);
	mlx_image_to_window(game->mlx, game->player->minimap, 10, 10);
	mlx_key_hook(game->mlx, key, game);
	mlx_cursor_hook(game->mlx, cursor, game);
	mlx_loop_hook(game->mlx, update_frame, game);// which keeps updating the frame over and over
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
