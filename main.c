/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:40:03 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/08 12:23:51 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
 

t_error **error;

int main() {
    char *input;
    t_command *command;
    char **split_input;

    while (1)
    {
        input = readline("minishell>");
        if (input == NULL) {
         printf("\nError reading input. Exiting...\n");
            exit(EXIT_FAILURE);
        }
        if (ft_strncmp(input, "exit", 4) == 0)
        {
            free(input);
            break;
        }
        command = ft_parser(input, &split_input);
        while (command)
        {
            printf("command=%s\n", command->command);
            while (command->redirection)
            {
                printf("file=%s id=%d\n", command->redirection->file,
                    command->redirection->identifer);
                    command->redirection = command->redirection->next;
            }
            command = command->next;
        } 
        if (command && command->redirection)
            ft_lstclear_redi(&(command->redirection));
        if (command)
            ft_lstclear_command(&command);
        free(input);
        ft_free(split_input);
    }
    if (command && command->redirection)
        ft_lstclear_redi(&(command->redirection));
    if (command)
        ft_lstclear_command(&command);
    return 0;
}