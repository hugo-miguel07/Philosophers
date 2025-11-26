/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:44:36 by htavares          #+#    #+#             */
/*   Updated: 2025/04/15 11:38:38 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*strdup;

	i = 0;
	while (s[i] != '\0')
		i++;
	strdup = (char *)malloc((i + 1) * sizeof(char));
	if (!strdup)
		return ((void *)0);
	i = 0;
	while (s[i] != '\0')
	{
		strdup[i] = s[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s1 = "Tung Tung Tung Sahur";
	char *s2 = ft_strdup(s1);
	printf("string dup: %s\n", s2);
	return (0);
}
*/
