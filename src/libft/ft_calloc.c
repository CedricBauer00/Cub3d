/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:47:55 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:59:05 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int main() {
//     // Allocate memory for an array of 5 integers
//     // int *arr = (int *)ft_calloc(0, sizeof(int));
//     int *arr = calloc(0, sizeof(int));
//     if (arr == NULL) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }
//     // Display the allocated memory, should be initialized to 0
//     for (int i = 0; i < 5; i++) {
//         printf("%d ", arr[i]);  // Should print: 0 0 0 0 0
//     }
//     printf("\n");
//     // Free the allocated memory
//     free(arr);
//     return 0;
// }