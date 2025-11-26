/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:49:35 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 11:29:21 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charinset(int c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*stoalloc;

	if (!s1 || !set)
		return ((void *)0);
	i = 0;
	while ((s1[i] != '\0') && charinset(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && charinset(s1[j - 1], set))
		j--;
	stoalloc = (char *)malloc((j - i + 1) * sizeof(char));
	if (!stoalloc)
		return ((void *)0);
	k = 0;
	while (s1[i] != '\0' && i < j)
	{
		stoalloc[k] = s1[i];
		i++;
		k++;
	}
	stoalloc[k] = '\0';
	return (stoalloc);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "Brr Capuccino Assassino Brr";
	char	*set = "Brr ";
	char	*trim = ft_strtrim(s1, set);
	printf("string :%s\n", s1);
	printf("set :%s\n", set);
	printf("trimmed :%s", trim);
	return (0);
}
*/
