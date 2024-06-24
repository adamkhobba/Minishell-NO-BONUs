/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:14:54 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/24 07:20:15 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_check_pipes(t_link *link, t_command **command)
{
    t_link *tmp;
    t_command *command_tmp;
    t_error *error_node;

    command_tmp = *command;
    tmp = link;
    while (tmp)
    {
        if (tmp && tmp->identifer == PIPE)
        {
            if (tmp && tmp->prev && tmp->next)
            {
                    tmp = tmp->next;
                    ft_check_command(tmp, &command_tmp->next);
                    ft_main_checker(tmp, &command_tmp->next); 
                    break;
            }
            else 
            {
                error_node = ft_lstnew_error(ERROR_PIPE);
                ft_lstadd_back_error(error, error_node);
                return (0);
            }
        }
            tmp = tmp->next;
    }
    return (1);
}
