/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:19:00 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/19 15:30:19 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int main ()
{
	t_list	*node1;
	t_list	*node0;
	int	n;
	int	n2;
	int	n1;

	node1 = malloc(sizeof(t_list));
	node1->next = malloc (sizeof(t_list));
	node0 = malloc(sizeof(t_list));

	n = 42;
	n1= 1337;
	n2 = 21;

	node1->content = &n;
	node1->next->content =&n1;
	node1->next->next = NULL;
	node0->content = &n2;

	ft_lstadd_front(&node1,node0);

	t_list	*current;

	current = node0;
	while (current)
	{
		printf("%d",*(int*)current->content);
		current = current->next;
	}
}*/
