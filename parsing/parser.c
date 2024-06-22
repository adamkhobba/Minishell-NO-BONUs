/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:11:52 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/22 13:52:34 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    ft_main_checker(t_link *link, t_command **command)
{
    t_error *error_node;

    // if (!ft_quote_handler(&link))
    // {
    //     error_node = ft_lstnew_error(ERROR_QUOTE);
    //     ft_lstadd_back_error(error, error_node);
    //     ft_lstclear(&link);
    //     return (NULL);
    // }
    if (!command)
    {
        error_node = ft_lstnew_error(ERROR_COMMAND);
        ft_lstadd_back_error(error, error_node);
        return ;
    }
    (*command)->redirection = NULL;
    if (!ft_check_redirections(link, &((*command)->redirection)))
    {
        ft_free_command(command);
        return ;
    }
    (*command)->args = NULL;
    (*command) = ft_set_args(link, *command);
    ft_check_pipes(link, command);
}

t_command *ft_parser(char *input)
{
    t_link *link;
    t_command *command;
    char **split_input;

    command = NULL; 
    split_input = ft_lexer(input);
    link = ft_def_type(split_input);
    ft_check_command(link, &command);
    ft_main_checker(link, &command);
    if (!command)
    {
        ft_free_command(&command);
        return (NULL);
    }
    ft_lstclear(&link);
    ft_free(split_input);
    return (command);
}
