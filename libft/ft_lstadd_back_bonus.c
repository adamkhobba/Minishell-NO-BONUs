/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:05:30 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/19 15:32:37 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (NULL == lst)
		return ;
	if (NULL == *lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
int main ()
{
	t_list	*node1;
	t_list	*node_add;
	int	n;
	int	n2;
	int	n1;

	node1 = malloc(sizeof(t_list));
	node1->next = malloc (sizeof(t_list));
	node_add= malloc(sizeof(t_list));

	n = 42;
	n1= 1337;
	n2 = 21;

	node1->content = &n;
	node1->next->content =&n1;
	node1->next->next = NULL;
	node_add->content = &n2;

	ft_lstadd_back(&node1,node_add);

	t_list	*current;

	current = node1;
	while (current)
	{
		printf("%d",*(int*)current->content);
		current = current->next;
	}
	return (0);
}*/
