/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:27:36 by htavares          #+#    #+#             */
/*   Updated: 2025/04/25 13:04:53 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((n > 0) && (*s1) && (*s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		s1--;
		s2--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "Brr Brr Patapim";
	char	*s2 = "Brr Patapim";
	size_t	size = 4;
	printf("string 1: %s\n", s1);
	printf("String 2: %s\n", s2);
	printf("size: %zu\n", size);
	printf("strncmp: %d", ft_strncmp(s1, s2, size));
	return (0);
}
*/
