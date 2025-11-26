/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:19:53 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 14:40:59 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > ((size_t) - 1) / size)
		return ((void *)0);
	result = (void *)malloc(nmemb * size);
	if (!result)
		return ((void *)0);
	ft_bzero(result, nmemb * size);
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*toallocate = ft_calloc(6, sizeof(char));
	int	i = 0;
	while (i < 6)
	{
		printf("%s\n", &toallocate[i]);
		i++;
	}
}
*/
