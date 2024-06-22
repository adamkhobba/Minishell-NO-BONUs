/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:41:52 by adam              #+#    #+#             */
/*   Updated: 2024/06/04 09:52:14by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_check_less(t_link *link, t_redirection **file)
{
    t_redirection *node;
    t_error *error_node;

    if (link->identifer == LESS)
    {
        if (link->next && link->next->identifer == STR)
        {
            node = ft_lstnew_redi(link->next->command);
            node->identifer = LESS;
            ft_lstadd_back_redi(file, node);
            return (1);
        }
        else 
        {
            error_node = ft_lstnew_error(ERROR_LESS);
            ft_lstadd_back_error(error, error_node);
            return (0);
        }
    }
            return (1);
}

int ft_check_lessless(t_link *link, t_redirection **file)
{
    t_redirection *node;
    t_error *error_node;

    if (link->identifer == LESSLESS)
    {
        if (link->next && link->next->identifer == STR)
        {
            node = ft_lstnew_redi(link->next->command);
            node->identifer = LESSLESS;
            ft_lstadd_back_redi(file, node);
            return (1);
        }
        else 
        {
            error_node = ft_lstnew_error(ERROR_LESSLESS);
            ft_lstadd_back_error(error, error_node);
            return (0);
        }
    }
            return (1);
}

int ft_check_great(t_link *link, t_redirection **file)
{
    t_redirection *node;
    t_error *error_node;

    if (link->identifer == GREAT)
    {
        if (link->next && link->next->identifer == STR)
        {
            node = ft_lstnew_redi(link->next->command);
            node->identifer = GREAT;
            ft_lstadd_back_redi(file, node);
            return (1);
        }
        else 
        {
            error_node = ft_lstnew_error(ERROR_GREAT);
            ft_lstadd_back_error(error, error_node);
            return (0);
        }
    }
            return (1);
}

int ft_check_greatgreat(t_link *link, t_redirection **file)
{
    t_redirection *node;
    t_error *error_node;

    if (link->identifer == GREATGREAT)
    {
        if (link->next && link->next->identifer == STR)
        {
            node = ft_lstnew_redi(link->next->command);
            node->identifer = GREATGREAT;
            ft_lstadd_back_redi(file, node);
            return (1);
        }
        else 
        {
            error_node = ft_lstnew_error(ERROR_GREATGREAT);
            ft_lstadd_back_error(error, error_node);
            return (0);
        }
    }
            return (1);
}

int ft_check_redirections(t_link *link, t_redirection **redirectoin)
{
    t_link *tmp;

    tmp = link;
    *redirectoin = NULL;
    while (tmp) 
    {
        if (tmp->identifer == PIPE)
            return (1);
        if (!ft_check_less(tmp, redirectoin))
            return (0);
        else if (!ft_check_great(tmp, redirectoin))
            return (0);
        else if (!ft_check_lessless(tmp, redirectoin))
            return (0);
        else if (!ft_check_greatgreat(tmp, redirectoin))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}
