/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:36:31 by akhobba           #+#    #+#             */
/*   Updated: 2024/05/30 19:37:38 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_link	*ft_dbl_lstnew(void *content)
{
	t_link	*node;

	node = malloc(sizeof(t_link));
	if (node == NULL)
		return (NULL);
	node->command = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
