/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:50:09 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 11:34:31 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((*ptr1 == *ptr2) && (n > 1))
	{
		ptr1++;
		ptr2++;
		n--;
	}
	return (*ptr1 - *ptr2);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = {0, 0, 127, 0};
	char	s2[] = {0, 0, 42, 0};
	size_t	size = 4;
	printf("s1: %s\ns2: %s\nn: %zu\n", s1, s2, size);
	printf("memcmp: %d", ft_memcmp(s1, s2, size));
}
*/
