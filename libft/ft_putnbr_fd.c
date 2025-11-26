/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:12:12 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 12:18:33 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	tenpow(size_t size)
{
	size_t	ten;

	ten = 1;
	while (size > 1)
	{
		ten *= 10;
		size--;
	}
	return (ten);
}

static size_t	get_size(long int nlong)
{
	size_t		wordsize;

	wordsize = 1;
	while (nlong > 9)
	{
		wordsize++;
		nlong /= 10;
	}
	return (wordsize);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nlong;
	int			tens;
	size_t		size;

	nlong = (long int)n;
	if (nlong < 0)
	{
		ft_putchar_fd('-', fd);
		nlong *= -1;
	}
	size = get_size(nlong);
	tens = tenpow(size);
	while (size-- > 0)
	{
		ft_putchar_fd(((nlong / tens) + 48), fd);
		nlong %= tens;
		tens /= 10;
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(321, 1);
	return (0);
}
*/
