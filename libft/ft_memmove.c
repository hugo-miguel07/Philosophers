/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:27:20 by htavares          #+#    #+#             */
/*   Updated: 2025/05/03 13:15:38 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	if ((dest < src) && (dest < (src + n)))
	{
		while (n > 0)
		{
			*ptrd = *ptrs;
			ptrd++;
			ptrs++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			ptrd[n - 1] = ptrs[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char test1[] = "123456789";
	char test11[] = "123456789";
	char test2[] = "abcdefghi";
	char test22[] = "abcdefghi";
	char test3[] = "ABCABCABC";
	char test33[] = "ABCABCABC";
	char test4[] = "SAMEADDRESS";
	char test44[] = "SAMEADDRESS";
	char test5[] = "short";
	char test55[] = "short";
	char test6[] = "";
	char test66[] = "";

	//Copiar sem sobreposição
	printf("Antes (sem sobreposição): %s\n", test1);
	ft_memmove(test1 + 5, test1, 4); // move "1234" para a posição 5
	memmove(test11 + 5, test11, 4);
	printf("ft Depois: %s\n", test1);
	printf("og Depois: %s\n\n", test11);

	//Copiar com sobreposição (para a frente)
	printf("Antes (sobreposição para frente): %s\n", test2);
	ft_memmove(test2 + 2, test2, 5);
	memmove(test22 + 2, test22, 5);
	printf("ft Depois: %s\n", test2);
	printf("og Depois: %s\n\n", test22);

	//Copiar com sobreposição (para trás)
	printf("Antes (sobreposição para trás): %s\n", test3);
	ft_memmove(test3, test3 + 3, 6);
	memmove(test33, test33 + 3, 6);
	printf("Depois: %s\n", test3);
	printf("og Depois: %s\n\n", test33);

	// 4. n == 0 (não deve fazer nada)
	printf("Antes (n == 0): %s\n", test4);
	ft_memmove(test4 + 2, test4, 0);
	memmove(test44 + 2, test44, 0);
	printf("Depois: %s\n", test4);
	printf("og Depois: %s\n\n", test4);

	// 5. dest == src (também não deve fazer nada)
	printf("Antes (dest == src): %s\n", test5);
	ft_memmove(test5, test5, 5);
	memmove(test55, test55, 5);
	printf("Depois: %s\n", test5);
	printf("og Depois: %s\n\n", test55);

	return (0);
}
*/
