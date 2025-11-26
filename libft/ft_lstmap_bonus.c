/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:49:21 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 14:40:18 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	newlst = (void *)0;
	if (!lst || !f || !del)
		return ((void *)0);
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			return ((void *)0);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
/*
void	*put_a(void *content)
{
	char	*str;

	str = (char *)content;
	*str = 'a';
	return (content);
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
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstmap(node1, put_a, free);
	temp = node1;
	printf("Depois:\n");
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}
*/
