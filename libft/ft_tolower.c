/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:42:07 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 11:38:29 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c < 91 && c > 64)
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char c = 'a';
	char a = ft_tolower(c);
	printf("%c\n", c);
	printf("%c", a);
	return (0);
}
*/
