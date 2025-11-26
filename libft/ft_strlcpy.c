/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:39:40 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 10:59:16 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		srcsize;
	const char	*og;

	og = src;
	srcsize = 0;
	while (*src)
	{
		src++;
		srcsize++;
	}
	while (dst && *og && (size) > 1)
	{
		*dst = *og;
		dst++;
		og++;
		size--;
	}
	if (dst && size > 0)
		*dst = '\0';
	return (srcsize);
}
/*
#include <stdio.h>
int	main(void)
{
	char	dest[10];
	ft_memset(dest, 'A', 10);
	char	*src = "coucou";
	size_t	size = 7;
	size_t result = ft_strlcpy(dest, src, size);
	printf("dest:%s\n", dest);
	printf("source:%s\n", src);
	printf("%zu\n", result);

	return (0);
}
*/
