/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:58:27 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:58:50 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t			counter;
// 	unsigned char	*string;
// 	string = (unsigned char *)s;	
// 	counter = 0;
// 	while (counter < n)
// 	{
// 		string[counter] = 0;
// 		counter++;
// 	}
// }
// int main()
// {
// 	char str[] = "asdasd";
// 	printf("%s\n", ft_bzero(str, 4));
// 	return (0);
// }
