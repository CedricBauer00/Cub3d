/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:32:36 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/25 13:33:15 by bolcay           ###   ########.fr       */
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

