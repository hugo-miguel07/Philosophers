/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 07:47:18 by htavares          #+#    #+#             */
/*   Updated: 2025/04/15 08:30:58 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while ((big[i] != '\0') && (i < len))
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return ((void *)0);
}
/*
#include <stdio.h>
int	main(void)
{
	const char *largestring = "Bombardino Crocodilo";
	const char *smallstring = "Croc";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 15);
	printf("ft_strnstr: %s\n", ptr);
}
*/
