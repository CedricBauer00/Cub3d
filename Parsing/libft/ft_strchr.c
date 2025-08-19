/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:04:15 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:56:16 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == (char)c)
			return ((char *)&str[counter]);
		counter++;
	}
	if ((char)c == '\0')
		return ((char *)(str + counter));
	return (NULL);
}

// int main()
// {
// 	char str[] = "Hello World!";
// 	printf("%s\n", ft_strchr(str, '\0'));
// 	return (0);
// }
// if (!(str = ft_strchr(str2, '\0')))
//         ft_print_result("NULL");
//     else
//     {
//         ft_print_result(str);
//         if (str != str2 + 7)
//             ft_print_result("\nReturn value is false");
//     }