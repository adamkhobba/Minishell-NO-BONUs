/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:39:23 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/07 17:20:53 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void  ft_lstadd_back_command(t_command **list, t_command *node)
{
    t_command *tmp;

    if (!list || !node)
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
t_command *ft_lstnew_command(char *content)
{
    t_command *node;

    node = malloc(sizeof(t_command));
    if (node == NULL)
        return (NULL);
    node->command = content;
    node->next = NULL;
    return (node);
}