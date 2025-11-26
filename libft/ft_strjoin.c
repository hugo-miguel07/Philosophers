/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:54:58 by htavares          #+#    #+#             */
/*   Updated: 2025/04/25 12:57:18 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*result;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	result = (char *)malloc((i + j + 1) * sizeof(char));
	if (!result)
		return ((void *)0);
	k = 0;
	while (k < i)
	{
		result[k] = s1[k];
		k++;
	}
	while (k < (i + j))
	{
		result[k] = s2[k - i];
		k++;
	}
	result[k] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "Tralalero ";
	char	*s2 = "Tralala";
	char	*s3 = ft_strjoin(s1, s2);
	printf("string1: %s\n", s1);
	printf("string2: %s\n", s2);
	printf("stringjoin: %s", s3);
}
*/
