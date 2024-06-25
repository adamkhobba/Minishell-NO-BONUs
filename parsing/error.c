/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:39:30 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/25 10:04:45 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_error()
{
    t_error *tmp;

    tmp = error;
    printf("error\n");
    while (tmp)
    {
        ft_putstr("minishell: ", 2);
        if (tmp->error == ERROR_QUOTE)
        {
            ft_putstr("quote error\n", 2);
            exit(1);
        }
        if (tmp->error == ERROR_COMMAND)
        {
            ft_putstr("command error\n", 2);
            exit(1);
        }
        if (tmp->error == ERROR_PIPE)
        {
            ft_putstr("pipe error\n", 2);
            exit(1);
        }
        if (tmp->error == ERROR_LESS)
        {
            ft_putstr("in redirection error\n", 2);
            exit(1);
        }
        tmp = tmp->next;
    }
}
