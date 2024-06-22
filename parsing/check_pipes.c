/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:14:54 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/22 19:04:28 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_check_pipes(t_link *link, t_command **command)
{
    t_link *tmp;
    t_command *command_tmp;
    t_error *error_node;

    tmp = link;
    command_tmp = *command;
    printf("---------------\n");
    while (tmp)
    {
          printf("command:%s, id:%d\n", tmp->command, tmp->identifer);
          tmp = tmp->next;
    }
    tmp = link;
    while (tmp)
    {
        if (tmp->identifer == PIPE)
        {
            if (tmp->prev && tmp->next)
                {
                    ft_check_command(tmp->next, &command_tmp->next);
                    ft_main_checker(tmp->next, &command_tmp->next); 
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