/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:07:00 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 10:41:57 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	finalsize;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	finalsize = dstlen + srclen;
	while (*dst)
		dst++;
	if (size <= dstlen)
		return (size + srclen);
	while (*src && (size - dstlen - 1) > 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (finalsize);
}
/*
#include <stdio.h>
int	main(void)
{
	char	dest[] = "QUARENTA";
	char	*src = " E DOIS";
	size_t	size = 12;
	size_t result = ft_strlcat(dest, src, size);
	printf("%s\n", dest);
	printf("%zu\n", result);

	return (0);
}
*/
