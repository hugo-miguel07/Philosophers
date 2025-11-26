/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:47:28 by htavares          #+#    #+#             */
/*   Updated: 2025/05/01 13:54:27 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
/*
#include <stdio.h>
int     main(void)
{
        t_list *lst;
        t_list *new;

        lst = malloc(sizeof(t_list));
        if (!lst)
                return (1);
        new = malloc(sizeof(t_list));
        if (!new)
                return (1);

        lst->content = "2";
        new->content = "1";

        lst->next = NULL;
        new->next = NULL;

        printf("Antes: %s %s\n", (char*)new->content, (char*)lst->content);

        ft_lstadd_back(&lst, new);
        printf("Depois: %s %s\n", (char*)lst->content,
		 (char*)lst->next->content);
        free(lst->next);
        free(lst);
        return (0);
}
*/
