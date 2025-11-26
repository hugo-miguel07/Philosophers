/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:32:22 by htavares          #+#    #+#             */
/*   Updated: 2025/04/23 10:31:41 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	tenpow(size_t size, int n)
{
	size_t	ten;

	ten = 1;
	if (n < 0)
		size--;
	while (size > 1)
	{
		ten *= 10;
		size--;
	}
	return (ten);
}

static size_t	get_size(int n)
{
	size_t		wordsize;
	long int	nlong;

	wordsize = 1;
	nlong = (long int)n;
	if (nlong < 0)
	{
		wordsize++;
		nlong *= -1;
	}
	while (nlong > 9)
	{
		wordsize++;
		nlong /= 10;
	}
	return (wordsize);
}

void	writenbr(size_t tens, char *strnum, int n)
{
	size_t		i;
	long int	nlong;

	i = 0;
	nlong = (long int)n;
	if (nlong < 0)
	{
		strnum[i++] = '-';
		nlong *= -1;
	}
	while (tens > 0)
	{
		strnum[i++] = (nlong / tens) + 48;
		nlong %= tens;
		tens /= 10;
	}
	strnum[i] = '\0';
}

char	*ft_itoa(int n)
{
	size_t		wordsize;
	char		*strnum;

	wordsize = get_size(n);
	strnum = (char *)malloc((wordsize + 1) * sizeof(char));
	if (!strnum)
		return ((void *)0);
	writenbr(tenpow(wordsize, n), strnum, n);
	return (strnum);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
	return (0);
}
*/
