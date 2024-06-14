/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:14:54 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/14 11:30:02 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_check_pipes(t_link *link, t_command **command)
{
    t_link *tmp;
    t_error *error_node;

    tmp = link;
    while (tmp)
    {
        if (tmp->identifer == PIPE)
        {
            if (tmp->prev && tmp->next)
                (*command) = ft_main_checker(tmp->next); 
            else 
            {
                error_node = ft_lstnew_error(ERROR_PIPE);
                ft_lstadd_back_error(&error, error_node);
                return (0);
            }
        }
        link = link->next;
    }
    return (1);
}