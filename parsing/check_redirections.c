/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:41:52 by adam              #+#    #+#             */
/*   Updated: 2024/06/03 14:21:48 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_check_pipe_redirections(t_link *link, t_command *command)
{
    if (!ft_check_less(link, command))
        return (0);
    else if (!ft_check_great(link, command))
        return (0);
    else if (!ft_check_lessless(link, command))
        return (0);
    else if (!ft_check_greatgreat(link, command))
        return (0);
    else if (!ft_check_pipe(link, command))
        return (0);
    return (1);
}
int ft_check_pipe(t_link *link, t_command *command)
{
    while (link)
    {
        if (link->identifer == PIPE)
        {
            if (link->next->identifer == STR && link->prev && link->)
        }

    }
}
int ft_check_less(t_link *link, t_command *command)
{
    while (link)
    {
            if (link->identifer == LESS)
            {
                if (link->next->identifer == STR)
                {
                    command->redirection->identifer = LESS;
                    command->redirection->file = ft_strdup(link->next->command);
                    command = command->next;
                }
                else 
                {
                    // here it should be an error handling related to error struct 
                    return (0);
                }
            }            
    }
            return (1);
}

int ft_check_great(t_link *link, t_command *command)
{
    while (link)
    {
            if (link->identifer == GREAT)
            {
                if (link->next->identifer == STR)
                {
                    command->redirection->identifer = GREAT; 
                    command->redirection->file = ft_strdup(link->next->command);
                    command->redirection = command->redirection->next;
                }
                else 
                {
                    // here it should be an error handling related to error struct 
                    return (0);
                }
            }            
    }
            return (1);
}
int ft_check_lessless(t_link *link, t_command *command)
{
    while (link)
    {
            if (link->identifer == LESSLESS)
            {
                if (link->next->identifer == STR)
                {
                    command->redirection->identifer = LESSLESS;
                    command->redirection->file = ft_strdup(link->next->command);
                    command->redirection = command->redirection->next;
                }
                else 
                {
                    // here it should be an error handling related to error struct
                    return (0);
                }
            }            
    }
            return (1);
}

int ft_check_greatgreat(t_link *link, t_command *command)
{
    while (link)
    {
            if (link->identifer == GREATGREAT)
            {
                if (link->next->identifer == STR)
                {
                    command->redirection->identifer = GREATGREAT;
                    command->redirection->file = ft_strdup(link->next->command);
                    command->redirection = command->redirection->next;
                }
                else 
                {
                    // here it should be an error handling related to error struct
                    return (0);
                }
            }            
    }
            return (1);
}
