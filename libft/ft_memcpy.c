/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:50:42 by htavares          #+#    #+#             */
/*   Updated: 2025/04/25 16:21:11 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	while (n > 0)
	{
		*ptrd = *ptrs;
		ptrd++;
		ptrs++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
int main() {
    char *src = "Quarenta";
    char dest[20];

    ft_memcpy(dest, src, strlen(src) + 1);
    printf("dest: %s\n", dest);

    return 0;
}
*/
