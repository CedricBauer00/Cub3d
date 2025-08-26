/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:09:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/26 14:57:27 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	here we have the normalised angle function. it's used to make sure
	the angle is between 0 and 2pi
*/

double	normalised_angle(double angle)
{
	if (angle < 0)
		angle += 2.0 * PI;
	if (angle >= 2.0 * PI)
		angle -= 2.0 * PI;
	return (angle);
}
