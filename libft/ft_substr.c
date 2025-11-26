/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:17:23 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 11:09:03 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	while (s[start + i] != '\0')
	{
		if (i >= len)
			break ;
		i++;
	}
	result = (char *)malloc((i + 1) * sizeof(char));
	if (!result)
		return ((void *)0);
	len = i;
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s = "linguini";
	char *subs = ft_substr(s, 1, 1);

	printf("Original: %s\n", s);
	printf("substring: %s", subs);
	return (0);
}
*/
