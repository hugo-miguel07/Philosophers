/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:32:22 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 11:46:50 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	size_t	strsize;
	size_t	i;

	if (!s || !f)
		return ((void *)0);
	strsize = ft_strlen(s);
	newstr = (char *)malloc((strsize + 1) * sizeof(char));
	if (!newstr)
		return ((void *)0);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
char	ft_test(unsigned int n, char c)
{
	c += n;
	return (c);
}
#include <stdio.h>
 int main ()
{
	char	*str = "ola";
	printf ("%s", ft_strmapi(str, ft_test));
}
*/
