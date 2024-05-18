/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:22:35 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/19 20:46:10 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*twp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		twp = current;
		current = current->next;
		ft_lstdelone(twp, del);
	}
	*lst = NULL;
}
/*
void	del(void *data)
{
		free(data);
}

int main ()
{
	t_list	*node_0;

	node_0 = malloc(sizeof(t_list));
	node_0->next = malloc(sizeof(t_list));
	node_0->next->next = malloc(sizeof(t_list));

	node_0->content = ft_strdup("hhi");
	node_0->next->content = ft_strdup("suu");
	node_0->next->next = NULL;

	ft_lstclear(&node_0,del);
	return (0);
}*/
