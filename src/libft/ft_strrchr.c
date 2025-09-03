/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:04:15 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:07:34 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	counter;
	char	*i;
	int		last;

	last = ft_strlen(str);
	i = NULL;
	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == (char)c)
			i = (char *)(str + counter);
		counter++;
	}
	if ((char)c == '\0')
		return ((char *)(str + last));
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	char *test = "teste";
// 	printf("%s\n", ft_strrchr(test, '\0'));
// 	return 0;
// }
