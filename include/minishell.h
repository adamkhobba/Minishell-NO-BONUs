/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:19:40 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/03 14:35:58 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_type
{
    STR,
    LESS,
    GREAT,
    LESSLESS,
    GREATGREAT, 
    PIPE
} t_type;

typedef struct s_redirection
{
    t_type identifer;
    char *file;
    struct s_redirection *next;
} t_redirection;

typedef struct s_error
{
    int error;
    struct s_error *next;
} t_error;

typedef struct s_command
{
    char *command;
    char **args;
    t_redirection *redirection; 
    struct s_command *next;
}t_command;

typedef struct s_link
{
    char *command;
    t_type identifer;
    struct s_link *prev;
    struct s_link *next;
}t_link;

/*execution*/

/*Parsing*/

//src
char	**ft_lexer(char *input);
int ft_parser(char *input);
t_link *ft_def_type(char **input);
t_command *ft_check_command(t_link *link);

//utils
void	            *free_str(char **tab, int c);
int                 ft_strchr(int c, const char *s);
void                ft_free(char **str);
char				**ft_split(char *str, char *c);
void				ft_putstr(char *s, int fd);
int					ft_isdigit(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_strdup_pro(char **s);
char				*ft_strdup(const char *s);
int					ft_count_strs(char **s);
int					ft_strlen(const char *str);
long				ft_atoi(const char *nptr);
char				*ft_strjoin(char *s1, char const *s2);
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