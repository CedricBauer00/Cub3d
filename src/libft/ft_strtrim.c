/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:28:48 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:55:55 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	while (s1[counter])
	{
		if (ft_strchr(set, s1[counter]) == NULL)
			break ;
		counter++;
	}
	i = ft_strlen(s1);
	while (i > counter)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i--;
	}
	return (ft_substr(s1, counter, i - counter + 1));
}

// int main()
// {
// 	char s1[] = "   Hello WOrld!    ";
// 	char set[] = " ";
// 	printf("%s\n", ft_strtrim(s1, set));
// 	return (0);
// }