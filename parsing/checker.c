/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:58:49 by akhobba           #+#    #+#             */
/*   Updated: 2024/05/29 11:22:17 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int ft_check_type(char *command)
{
    if (ft_strncmp(command, "ls", ft_strlen(command)))
        return (1);
    return (0);
}
int ft_check_command(t_link *link)
{
    t_link *tmp;

    tmp = link;
    while (tmp)
    {
        if (tmp->identifer == STR)
           break; 
        tmp = tmp->next;
    }
    if (ft_check_type(tmp->command))
        return (0);
}