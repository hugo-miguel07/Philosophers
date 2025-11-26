/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:17:03 by htavares          #+#    #+#             */
/*   Updated: 2025/04/25 15:27:11 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s1, char c)
{
	size_t	words;

	words = 0;
	while (*s1)
	{
		while (*s1 == c)
			s1++;
		if (*s1 != c && *s1 != '\0')
		{
			words++;
			while (*s1 != c && *s1 != '\0')
				s1++;
		}
	}
	return (words);
}

static void	freeall(char **splitstr)
{
	size_t	i;

	i = 0;
	while (splitstr[i])
	{
		free(splitstr[i]);
		i++;
	}
	free(splitstr);
}

static void	allocwords(char **splitstr, char const *s1, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*s1)
	{
		i = 0;
		while (*s1 == c)
			s1++;
		while (*s1 != c && *s1 != '\0')
		{
			i++;
			s1++;
		}
		if (i > 0)
		{
			splitstr[j] = (char *)ft_calloc((i + 1), sizeof(char));
			if (!splitstr[j])
			{
				freeall(splitstr);
				return ;
			}
			j++;
		}
	}
}

static void	storewords(char **splitstr, char const *s1, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s1)
	{
		j = 0;
		while (*s1 == c)
			s1++;
		if (*s1 && *s1 != c)
		{
			while (*s1 != c && *s1 != '\0')
				splitstr[i][j++] = *s1++;
			i++;
		}
	}
}

char	**ft_split(char const *s1, char c)
{
	char	**splitstr;
	size_t	words;

	if (!s1)
		return ((void *)0);
	words = countwords(s1, c);
	splitstr = (char **)malloc((words + 1) * sizeof(char *));
	if (!splitstr)
		return ((void *)0);
	allocwords(splitstr, s1, c);
	if (!splitstr)
		return ((void *)0);
	storewords(splitstr, s1, c);
	splitstr[words] = (void *)0;
	return (splitstr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "  trulimero  trulicina   ";
	char	c = ' ';
	char	**split = ft_split(s1, c);
	printf("{");
	int	i;
	for (i = 0; i < 2; i++)
		printf("%s, ", split[i]);
	printf("%s}", split[i]);
	return (0);
}
*/
