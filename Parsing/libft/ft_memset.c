/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:13:36 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:56:27 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*str;

	str = (unsigned char *)b;
	counter = 0;
	while (counter < len)
	{
		str[counter] = (unsigned char)c;
		counter++;
	}
	return (b);
}

// int main()
// {
// 	char str[10];
// 	printf("%s\n", ft_memset(str, 'B', 10));
// 	return (0);
// }
// // int main() {
// //     char buffer[10];
//     // Initialize all bytes in buffer to 'A'
//     memset(buffer, 'A', sizeof(buffer));
//     // Print the buffer
//     for (int i = 0; i < sizeof(buffer); i++) {
//         printf("%c ", buffer[i]);
//     }
//     return 0;
// }