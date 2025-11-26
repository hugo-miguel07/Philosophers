/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:20:06 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 14:24:42 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prox;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		prox = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = prox;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	node1->content = ft_strdup("1");
	node2->content = ft_strdup("2");
	node3->content = ft_strdup("3");

	node1->next = node2;
	node1->next->next = node3;
	node3->next = NULL;

	ft_lstclear(&node2, free);
	while (node1)
	{
		printf("%s\n", (char *)node1->content);
		node1 = node1->next;
}
	return (0);
}
*/
