#include "../include/minishell.h"

void ft_init_link(t_link **list, char *str)
{
    void *tmp;
    
    tmp  = &str;
        *list = ft_lstnew(tmp);
    if (!ft_strcmp(str, "<"))
        (*list)->command->identifer = 1;
    else if (!ft_strcmp(str, ">"))
        (*list)->command->identifer = 2;
    else if (!ft_strcmp(str, "<<"))
        (*list)->command->identifer = 3;
    else if (!ft_strcmp(str, ">>"))
        (*list)->command->identifer = 4;
    else if (!ft_strcmp(str, "|"))
        (*list)->command->identifer = 5;
    else 
        (*list)->command->identifer = 6;
}

t_link *ft_lexer(char **input)
{
    int i;
    void *tmp;
    char **input;
    t_link *list;
    t_link node;

    while(input[i])
    {
        tmp = &input[i]; 
        list = ft_lstnew(tmp);
        if (!ft_strcmp(input, "<"))
            list->command->identifer = 1;
        else if (!ft_strcmp(input, ">"))
            list->command->identifer = 2;
        else if (!ft_strcmp(input, "<<"))
            list->command->identifer = 3;
        else if (!ft_strcmp(input, ">>"))
            list->command->identifer = 4;
        else if (!ft_strcmp(input, "|"))
            list->command->identifer = 5;
        else 
            list->command->identifer = 6;
        i++;
    }
    return (list);
}