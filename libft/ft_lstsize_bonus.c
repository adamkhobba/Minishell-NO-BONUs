/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:07:46 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/19 12:23:35 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		++size;
	}
	return (size);
}
/*
int	main(void)
{
	t_list	*node_1;
	int	n;
	int	n1;

	node_1 = malloc(sizeof(t_list));
	node_1->next = malloc(sizeof(t_list));

	node_1->content = &n;
	node_1->next->content = &n1;
	node_1->next->next = NULL;

	printf("%d",ft_lstsize(node_1));
	return (0);
}*/
