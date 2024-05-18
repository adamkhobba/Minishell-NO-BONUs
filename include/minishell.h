/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:19:40 by akhobba           #+#    #+#             */
/*   Updated: 2024/05/18 06:24:06 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
# define MINISHELL
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_command
{
    char *command;
    char **args;
    char *input;
    char *output;
    struct s_command *next;
} t_command;

typedef struct s_list
{
    struct s_command *command;
    struct s_list *next;
}t_list;

/*Parsing*/

/*execution*/

#endif 