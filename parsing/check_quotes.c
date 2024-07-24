/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:36:47 by akhobba           #+#    #+#             */
/*   Updated: 2024/07/24 10:53:44 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_min(int a, int b)
{
    if (!a)
        return (b);   
    if (!b)
        return (a);
    if (a >= b)
        return (b);    
    else
        return (a);
}

char ft_char(int a, int b, char c_a, char c_b)
{
    if (!a)
        return (c_b);   
    if (!b)
        return (c_a);
    if (a >= b)
        return (c_b);
    else
        return (c_a);
}

long ft_index_quote(char *input)
{
    char c;
    int start;
    int start_2;
    int end;
    long bin;

    start = ft_strchr('\"', input);
    start_2 = ft_strchr('\'', input);
    if (!start && !start_2)
        return (-1);
    c = ft_char(start, start_2, '\"', '\'');
    start = ft_min(start, start_2);
    end = ft_strchr(c, input + start);
    start--;
    if (!end)
        return (0);
    bin = start; 
    bin <<= 32;
    bin += end;
    return (bin);
}

char    *ft_remove_quote(char *str, int start, int end)
{
    char *output;
    int i;
    int j;

    j = 0;
    i = 0;
    output = malloc(ft_strlen(str) - 1);
    while (str[i])
    {
        if (i != start && i != end)
        {
            output[j] = str[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
    free(str);
    return (output);
}

int ft_quote_handler(t_link **list)
{
    t_link **tmp;
    long bin;
    int start;
    int end;

    tmp = list;
    while (*tmp)
    {
        bin = ft_index_quote((*tmp)->command);
        if (!bin)
            return (0);
        if (bin == -1)
            return (-1);
        start = bin >> 32;
        end = bin;
        (*tmp)->command = ft_remove_quote((*tmp)->command, start, end);
        (*tmp) = (*tmp)->next;
    }
    return (1);
}