/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:54:16 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/09 12:50:00 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	copy;
	char	number[10];
	int		i;

	copy = n;
	i = 0;
	if (copy == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (copy < 0)
	{
		copy *= -1;
		write (fd, "-", 1);
	}
	while (copy > 0)
	{
		number[i++] = copy % 10 + 48;
		copy /= 10;
	}
	while (i > 0)
	{
		write (fd, &number[--i], 1);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}
*/