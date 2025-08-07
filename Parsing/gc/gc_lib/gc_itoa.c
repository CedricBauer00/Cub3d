/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:14:58 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 14:22:39 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"

static int	ft_countint(int n)
{
	int		counter;

	counter = 0;
	if (n < 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*gc_itoa(int n, int id)
{
	char	*intrep;
	int		counter;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	counter = ft_countint(n);
	intrep = (char *)gc_malloc((counter + 1) * sizeof(char), id);
	if (!intrep)
		return (0);
	if (n < 0)
	{
		n = -n;
		intrep[0] = '-';
	}
	intrep[counter] = '\0';
	counter--;
	while (n > 0)
	{
		intrep[counter] = (n % 10) + '0';
		counter--;
		n = n / 10;
	}
	return (intrep);
}