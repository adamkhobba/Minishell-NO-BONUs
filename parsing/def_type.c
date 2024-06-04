/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:11:17 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/04 12:26:02 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_link *ft_def_type(char **input)
{
    t_link *link;
    t_link *node;
    int i;

    i = 0;
    link = NULL;
    while (input[i])
    {
        node = ft_lstnew(input[i]);
        if (!ft_strncmp(input[i], "<", ft_strlen(input[i]))) 
            node->identifer = LESS;
        else if (!ft_strncmp(input[i], ">", ft_strlen(input[i]))) 
            node->identifer = GREAT;
        else if (!ft_strncmp(input[i], "<<", ft_strlen(input[i]))) 
            node->identifer = LESSLESS;
        else if (!ft_strncmp(input[i], ">>", ft_strlen(input[i]))) 
            node->identifer = GREATGREAT;
        else if (!ft_strncmp(input[i], "|", ft_strlen(input[i]))) 
            node->identifer = PIPE;
        else
            node->identifer = STR;
        ft_lstadd_back(&link, node);
        i++;
    }
    return (link);
} 
