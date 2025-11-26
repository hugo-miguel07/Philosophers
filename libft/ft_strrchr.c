/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:36:42 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 13:47:23 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	lastpos;
	char			symbol;

	i = 0;
	lastpos = 0;
	symbol = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == symbol)
			lastpos = i;
		i++;
	}
	if (s[i] == symbol)
		lastpos = i;
	if (s[lastpos] != symbol)
		return ((void *)0);
	return ((char *)&s[lastpos]);
}
/*
#include <stdio.h>
int     main(void)
{
        char    *s = "Bombini Goosini";
        char    c = 'n';
        printf("%s\n", s);
        s = ft_strrchr(s, c);

        printf("%s", s);
}
*/
