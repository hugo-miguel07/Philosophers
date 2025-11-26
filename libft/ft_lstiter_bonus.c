/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:37:33 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 14:33:11 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	put_a(void *content)
{
	char	*str;

	str = (char *)content;
	*str = 'a';
}
#include <stdio.h>
int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *temp;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	node1->content = ft_strdup("1");
	node2->content = ft_strdup("2");
	node3->content = ft_strdup("3");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	temp = node1;
	printf("Antes\n");
	while(temp)
	{
		printf("%s\n",  (char *)temp->content);
		temp = temp->next;
	}
	ft_lstiter(node1, put_a);
	temp = node1;
	printf("Depois:\n");
	while(temp)
	{
		printf("%s\n",  (char *)temp->content);
		temp = temp->next;
	}
}
*/
