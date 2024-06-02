/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:41:52 by adam              #+#    #+#             */
/*   Updated: 2024/06/02 08:45:08 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int ft_check_redirections(t_link *link)
{
    int i;

    i = 0;
    while (link)
    {
        if (link->identifer == LESS)
            {
                if (link->next->identifer == STR)
                    i++;
                else
                    return (0);
            }            
        link = link->next;
    }
    return (0);
}