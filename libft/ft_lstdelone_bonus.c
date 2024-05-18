/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:33:46 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/19 20:45:48 by akhobba          ###   ########.fr       */
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
void	del(void *data)
{
		free(data);
} int	main(void) {
		t_list	*node;
	int	*N;
	node = (t_list *)malloc(sizeof(t_list));
	node->next = (t_list *)malloc(sizeof(t_list));
	N = (int *)malloc(sizeof(int));
		*N = 42;
		node->content = N;
		node->next->next = NULL;

		ft_lstdelone(node, del);
		return (0);
}*/
