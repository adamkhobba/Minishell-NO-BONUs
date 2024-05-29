/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:11:52 by akhobba           #+#    #+#             */
/*   Updated: 2024/05/29 10:57:45 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



void ft_parser(char *input)
{
    char **split_input;
    t_link *link;

    split_input = ft_lexer(input);

    link = ft_def_type(split_input);
    free(split_input);
    ft_check_command(split_input);
    // ft_check_int();
    // ft_check_out();
    // ft_check_qoute();
    // ft_check_;
}