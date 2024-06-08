/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:40:03 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/08 08:54:48 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
 

t_error **error;

int main() {
    char *input;

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
        ft_parser(input);
        free(input);
    }
    return 0;
}