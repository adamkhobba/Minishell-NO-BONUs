/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:19:40 by akhobba           #+#    #+#             */
/*   Updated: 2024/05/22 18:22:30 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
# define MINISHELL
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_command
{
    char *content;
    char **args;
    char *input;
    char *output;
    int identifer;
    struct s_command *next;
} t_command;

typedef struct s_link
{
    struct s_command *command;
    struct s_link *next;
}t_link;

/*execution*/

/*Parsing*/

//utils
char				**ft_split(char *str, char c);
void				ft_putstr(char *s, int fd);
int					ft_isdigit(int c);
int					ft_strncmp(const char *s1, const char *s2, ssize_t n);
char				**ft_strdup_pro(char **s);
char				*ft_strdup(const char *s);
int					ft_count_strs(char **s);
int					ft_strlen(const char *str);
long				ft_atoi(const char *nptr);
char				*ft_strjoin(char *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, ssize_t n);
char				*ft_strdup(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

//link_ft
t_link				*ft_create_node(int nbr);
t_link				*ft_create_node(int nbr);
t_link				*ft_lstnew(void *content);
void				ft_lstadd_front(t_link **lst, t_link *ne);
int					ft_lstsize(t_link *lst);
t_link				*ft_lstlast(t_link *lst);
void				ft_lstadd_back(t_link **lst, t_link *ne);
void				ft_lstclear(t_link **lst);
void				ft_lstdelone(t_link *lst);
void				ft_lstiter(t_link *lst, void (*f)(void *));
t_link				*ft_lstmap(t_link *lst, void *(*f)(void *),
						void (*del)(void *));

#endif 