/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:48:33 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/19 21:07:18 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	f(void *v)
{
	*(int*)v = 42 + 1;
	}

int main ()
{
	t_list	*node;
	int	*N;

	node = malloc(sizeof(t_list));
	node->next = malloc(sizeof(t_list));
	N = malloc(sizeof(t_list));
	*N = 422;
	node->content = N;
	node->next = NULL;

	ft_lstiter(node,f);
	return (0);
}*/
