/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:47:35 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 13:53:40 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	length;

	length = 0;
	while (lst)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	t_list *node5;
	t_list *head;

	node1 = ft_lstnew("Node 1");
	node2 = ft_lstnew("Node 2");
	node3 = ft_lstnew("Node 3");
	node4 = ft_lstnew("Node 4");
	node5 = ft_lstnew("Node 5");

	node1->next = node2;
	node1->next->next = node3;
	node1->next->next->next = node4;
	node1->next->next->next->next = node5;

	head = node1;
	while(node1 != NULL)
	{
		printf("%s\n", (char *)node1->content);
		node1 = node1->next;
	}
	printf("Numero de Nodes: %d", ft_lstsize(head));
}
*/
