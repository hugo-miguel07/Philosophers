/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:02 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 14:00:40 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return ((void *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew("Node 1");
	node2 = ft_lstnew("Node 2");
	node3 = ft_lstnew("Node 3");

	node1->next = node2;
	node1->next->next = node3;
	node3->next = NULL;

	printf ("%s\n", (char *)ft_lstlast(node1)->content);
	printf ("%s\n", (char *)node3->content);
}
*/
