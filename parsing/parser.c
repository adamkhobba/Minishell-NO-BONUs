/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:11:52 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/13 12:36:59 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


t_command *ft_parser(char *input)
{
    t_link *link;
    t_error *error_node;
    t_command *command;
    char **split_input;

    command = NULL; 
    split_input = ft_lexer(input);
    link = ft_def_type(split_input);
    // if (!ft_quote_handler(&link))
    // {
    //     error_node = ft_lstnew_error(ERROR_QUOTE);
    //     ft_lstadd_back_error(error, error_node);
    //     ft_lstclear(&link);
    //     return (NULL);
    // }
    command = ft_check_command(link);
    if (!command)
    {
        error_node = ft_lstnew_error(ERROR_COMMAND);
        ft_lstadd_back_error(error, error_node);
        ft_free_command(&command);
        ft_lstclear(&link);
        return (NULL);
    }
    command->redirection = NULL;
    if (!ft_check_redirections(link, &(command->redirection)))
    {
        ft_free_command(&command);
        ft_lstclear(&link);
        return (NULL);
    }
    command->args = NULL;
    command = ft_set_args(link, command);
    ft_lstclear(&link);
    ft_free(split_input);
    return (command);
}
