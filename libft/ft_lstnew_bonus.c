/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:52:29 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 13:30:28 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return ((void *)0);
	newnode->content = content;
	newnode->next = (void *)0;
	return (newnode);
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


	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	node4 = malloc(sizeof(t_list));

	node1->content = "1";
	node2->content = "2";
	node3->content = "3";
	node4->content = "4";
	node5 = ft_lstnew("5");

	node1->next = node2;
	node1->next->next = node3;
	node1->next->next->next = node4;
	node1->next->next->next->next = node5;
	while(node1 != NULL)
	{
		printf("%s\n", (char *)node1->content);
		node1 = node1->next;
	}
}
*/
