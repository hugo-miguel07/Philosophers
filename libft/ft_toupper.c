/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:12:52 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 10:14:18 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char c = 'a';
	char a = ft_toupper(c);
	printf("%c\n", c);
	printf("%c", a);
	return (0);
}
*/
