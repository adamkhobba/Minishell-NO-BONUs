/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:11:52 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/04 11:33:44 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_parser(char *input)
{
    char **split_input;
    t_link *link;
    // t_error *node;
    t_command *command;

    split_input = ft_lexer(input);
    link = ft_def_type(split_input);
    command =  ft_check_command(link);
    // if (!command->command)
    // {
    //     node = ft_lstnew_error(ERROR_COMMAND);     
    //     ft_lstadd_back_error(error, node);
    //     return (0);
    // }
    // t_link *tmp = link;
    // while(tmp) 
    // {
    //     printf("command=%s type=%d\n", tmp->command, tmp->identifer);
    //     tmp = tmp->next;
    // }
    ft_free(split_input);
    //ft_check_redirecion(link, &(command->redirection)); 
    return (1);
}
