/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:06:13 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 14:10:39 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *temp;


	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));

	node1->content = ft_strdup("1");
	node2->content = ft_strdup("2");

	node1->next = node2;
	node2->next = NULL;

	temp = node1;
	ft_lstdelone(node2, free);
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}
*/
