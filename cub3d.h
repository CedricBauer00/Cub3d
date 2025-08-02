/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:15:15 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/02 13:29:36 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>

# define TS 64
# define WIDTH 1024
# define HEIGHT 512
typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_game
{
	mlx_t	*mlx;
	t_player *player;
}	t_game;

void	key(mlx_key_data_t keys, void *ptr);
int		paint_map(t_game *game, mlx_image_t *image);

#endif