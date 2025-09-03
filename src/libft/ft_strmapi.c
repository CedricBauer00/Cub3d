/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:47:49 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/18 15:37:36 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	size_t			len;
	char			*newstr;

	len = ft_strlen(s);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	counter = 0;
	while (s[counter] != '\0')
	{
		newstr[counter] = f(counter, s[counter]);
		counter++;
	}
	newstr[counter] = '\0';
	return (newstr);
}
