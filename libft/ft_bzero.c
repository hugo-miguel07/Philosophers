/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:29:29 by htavares          #+#    #+#             */
/*   Updated: 2025/04/25 16:10:19 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char str[20] = "Olá Mundo!";

	printf("Antes do bzero: %s\n", str);
	ft_bzero(str, 5);
	printf("Depois do bzero: ");
	for (int i = 0; i < 9; i++)
	{
		if (str[i] == '\0')
			printf("\\0");
		else
			putchar(str[i]);
	}
	return (0);
}
*/
