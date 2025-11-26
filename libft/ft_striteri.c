/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:27:46 by htavares          #+#    #+#             */
/*   Updated: 2025/05/03 12:33:07 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	ft_capitalize(unsigned int i, char *s)
{
	if (i < 0)
		return ;
	if (*s > 96 && *s < 123)
		*s -= 32;
}

#include <stdio.h>
int	main(void)
{
	char s[] = "Sahur";
	printf("String:%s\n", s);
	ft_striteri(s, ft_capitalize);
	printf("After striteri:%s", s);
	return (0);
}
*/
