/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:33:59 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/11 15:13:08 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_trim(char const *s, char const *set);
static int	my_other_trim(char const *s, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (ft_strdup(""));
	start = my_trim(s1, set);
	end = my_other_trim(s1, set);
	i = 0;
	if (start > end || start == ft_strlen(s1))
		return (ft_strdup(""));
	new = (char *)malloc ((end - start + 2) * sizeof(char));
	if (!new)
		return (NULL);
	while ((start + i) <= end)
	{
		new[i] = s1[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static int	my_trim(char const *s, char const *set)
{
	size_t	countdown;
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		countdown = 0;
		j = 0;
		while (set[j])
		{
			if (s[i] != set[j])
				countdown++;
			j++;
		}
		if (countdown == ft_strlen(set))
			return (i);
		i++;
	}
	return (ft_strlen(s));
}

static int	my_other_trim(char const *s, char const *set)
{
	size_t	countdown;
	int		i;
	int		j;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		countdown = 0;
		j = 0;
		while (set[j])
		{
			if (s[i] != set[j])
				countdown++;
			j++;
		}
		if (countdown == ft_strlen(set))
			return (i);
		if (i == 0)
			break ;
		i--;
	}
	return (0);
}

// int main()
// {
// 	char *s1 = "abcdba";
// 	char *set = "acb";
//     printf("%s", ft_strtrim(s1, set));
//     return (0);
// }
