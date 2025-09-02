/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:53:31 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/27 15:18:46 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

// int main()
// {
// 	// printf("%d\n", ft_isdigit(47));
// 	int    i = '0';
//     while (i <= '9')
//     {
//         printf("%d",ft_isdigit(i));
//         i++;
//     }
// 	return (0);
// }