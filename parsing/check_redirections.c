/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:41:52 by adam              #+#    #+#             */
/*   Updated: 2024/06/02 16:42:40 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int ft_check_redirections(t_link *link, t_command *command)
{
    int i;

    i = 0;
    while (link)
    {
            if (link->identifer == LESS)
            {
                if (link->next->identifer == STR)
                {
                    command->input = ft_strdup(link->next->command);
                    command = command->next;
                }
                else 
                    return (0);
            }            
            else if (link->identifer == GREAT)
            {
                if (link->next->identifer == STR)
                {
                    command->output = ft_strdup(link->next->command);
                    command = command->next;
                }
                else 
                    return (0);
            }
            else if (link->identifer == LESSLESS)
            {
                if (link->next->identifer == STR)
                {
                    command->append = ft_strdup(link->next->command);
                    command = command->next;
                }
                else 
                    return (0);
            }
            else if (link->identifer == GREATGREAT)
            {
                if (link->next->identifer == STR)
                {
                    command->heredoc = ft_strdup(link->next->command);
                    command = command->next;
                }
                else 
                    return (0);
            }
        link = link->next;
    }
    return (0);
}
