/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:36:31 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/08 11:49:55 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_link	*ft_lstnew(void *content)
{
	t_link	*node;

	node = malloc(sizeof(t_link));
	if (node == NULL)
		return (NULL);
	node->command = content;
	node->next = NULL;
	return (node);
}
