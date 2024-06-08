/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_redi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:57:52 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/07 16:17:45 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_lstadd_back_redi(t_redirection **list, t_redirection *node)
{
    t_redirection *tmp;

    printf("node->file = %s\n", node->file);
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

t_redirection    *ft_lstnew_redi(char *content)
{
    t_redirection	*node;

    node = malloc(sizeof(t_redirection));
    if (node == NULL)
        return (NULL);
    node->file = content;
    node->next = NULL;
    return (node);
}