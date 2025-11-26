/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:54:08 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 10:29:06 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	byte;

	byte = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == byte)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return ((void *)0);
}
/*
#include <stdio.h>
int main(void)
{
	char	*str = "Hello, world!";
	char	*found = ft_memchr(str, 'o', strlen(str));

	if (found)
		printf("Found: %s\n", found);
	else
		printf("Not found.\n");
	return (0);
}
*/
