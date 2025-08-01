/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:07:49 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/10 16:36:56 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenght(int n);
static char	*zero_handling(int n);

char	*ft_itoa(int n)
{
	long	copy;
	int		j;
	char	*number;

	copy = (long)n;
	j = lenght(n);
	if (n == 0)
		number = zero_handling(n);
	else
		number = (char *)malloc(lenght(n) + 1);
	if (!number)
		return (NULL);
	if (copy < 0)
	{
		copy *= -1;
		number[0] = '-';
	}
	while (copy > 0 && n != 0)
	{
		number[--j] = copy % 10 + 48;
		copy /= 10;
	}
	number[lenght(n)] = '\0';
	return (number);
}

static int	lenght(int n)
{
	long	i;
	int		count;

	i = n;
	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	if (i == 0)
		count++;
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char	*zero_handling(int n)
{
	char	*zero;

	zero = (char *)malloc(n + 2);
	if (!zero)
		return (NULL);
	zero[0] = '0';
	return (zero);
}
/*
int	main(void)
{
    int n = -623;
    printf("%s", ft_itoa(n));
    return (0);
}
*/