/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:39:30 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/25 10:27:36 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_error()
{
    t_error *tmp;
    int nbr;

    nbr = 1;
    tmp = error;
    while (tmp)
    {
        ft_putstr("minishell: ", 2);
        if (tmp->error == ERROR_QUOTE)
        {
            ft_putstr("quote error\n", 2);
            nbr = 0;
        }
        if (tmp->error == ERROR_COMMAND)
        {
            ft_putstr("command error\n", 2);
            nbr = 0;
        }
        if (tmp->error == ERROR_PIPE)
        {
            nbr = 0;
            ft_putstr("pipe error\n", 2);
        }
        if (tmp->error == ERROR_LESS)
        {
            ft_putstr("in redirection error\n", 2);
            nbr = 0;
        }
        tmp = tmp->next;
    }
   ft_lstclear_error(&error);
    return (nbr);
}
