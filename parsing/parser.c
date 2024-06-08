/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:11:52 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/08 12:12:48 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_command *ft_parser(char *input, char ***split_input)
{
    t_link *link;
    t_error *error_node;
    t_command *command;

    command = NULL;
    error_node = NULL;
    *split_input = ft_lexer(input);
    link = ft_def_type(*split_input);
    command = ft_check_command(link);
    if (!command)
    {
        error_node = ft_lstnew_error(ERROR_COMMAND);     
        ft_lstadd_back_error(error, error_node);
        return (NULL);
    }
    command->redirection = NULL;
    if (!ft_check_redirections(link, &(command->redirection)))
        return (NULL);
    ft_lstclear(&link);
    return (command);
}
