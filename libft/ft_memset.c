/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:21:24 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 09:38:08 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	byte;

	ptr = (unsigned char *)s;
	byte = (unsigned char)c;
	while (n > 0)
	{
		*ptr = byte;
		ptr++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
int main()
{
	//test para strings
	char str[50] = "Hello, this is a test string.";

	printf("Original string: %s\n", str);
	ft_memset(str, 'X', 5);
	printf("Modified string: %s\n", str);

	//test para ints
	int arr[5] = {1, 2, 3, 4, 5};
	int i = -1;

	printf("Original array: ");
	while (i++ < 4)
		printf("%d ", arr[i]);
	printf("\n");

	ft_memset(arr, 0, (3 * sizeof(int)));

	printf("Modified array: ");
	i = -1;
	while (i++ < 4)
        	printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
*/
