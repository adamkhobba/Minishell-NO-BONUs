/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:16:10 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/04 10:51:03 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_lstadd_back_error(t_error **list, t_error *node)
{
    t_error *tmp;

    if (!list)
        return ;
    if (!*list)
    {
        *list = node;
        return ;
    }
    tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}
t_error *ft_lstnew_error(t_errorn num_error)
{
    t_error *node;

    node = malloc(sizeof(t_error));
    node->next = NULL;
    node->error = num_error;
    return (node);
}