/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:19:40 by akhobba           #+#    #+#             */
/*   Updated: 2024/07/25 12:23:47 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_type
{
	STR,
	LESS,
	GREAT,
	LESSLESS,
	GREATGREAT,
	PIPE
}							t_type;

typedef enum e_errorn
{
	ERROR_LESS,
	ERROR_LESSLESS,
	ERROR_GREAT,
	ERROR_GREATGREAT,
	ERROR_PIPE,
	ERROR_COMMAND,
	ERROR_QUOTE
}							t_errorn;

typedef struct s_error
{
	t_errorn				error;
	struct s_error			*next;
}							t_error;

/* error guide
	0: error in less(in) redirection
	1: error in lessless(out) redirection
	2: error in great(append) redirection
	3: error in greatgreat(append) redirection
	4: error in pipe redirection
	5: error in command (no command found)
*/

typedef struct s_redirection
{
	t_type					identifer;
	char					*file;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_command
{
	char					*command;
	char					**args;
	t_redirection			*redirection;
	struct s_command		*next;
}							t_command;

typedef struct s_link
{
	char					*command;
	t_type					identifer;
	struct s_link			*prev;
	struct s_link			*next;
}							t_link;

// global var
extern t_error				*g_error;

// env linked list
typedef struct env_store
 {
    char *key;
    char *value;
    struct env_store *next;
} env_store;

/*execution*/
char	*getenv_value(char *key, env_store *env_list);

/*Parsing*/

// src
char						**ft_lexer(char *input);
t_command					*ft_parser(char *input);
t_link						*ft_def_type(char **input);
void						ft_check_command(t_link *link, t_command **command);
int							ft_check_redirections(t_link *link,
								t_redirection **redirectoin);
t_command					*ft_set_args(t_link *link, t_command *command);
char						**ft_strjoin_pro(char **s1, char **s2);
int							ft_check_pipes(t_link *link, t_command **command);
void						ft_main_checker(t_link *link, t_command **command);
int							ft_quote_handler(t_link **list);

// error_ft
t_error						*ft_lstnew_error(t_errorn num_error);
void						ft_lstadd_back_error(t_error **list, t_error *node);
void						ft_lstclear_error(t_error **lst);
void						ft_add_erro(t_errorn errorn);

// command_ft
t_command					*ft_lstnew_command(char *content);
void						ft_lstadd_back_command(t_command **list,
								t_command *node);
void						ft_lstclear_command(t_command **list);
void						ft_free_command(t_command **command);

// expand_ft
int	ft_base_expand(t_link *link, env_store *env);



// utils
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int							ft_count_strs(char **s);
int							check_quote(char *str, int a);
int							ft_error(void);
void						free_str(char **tab, int c);
int							ft_strchr(int c, const char *s);
void						ft_free(char **str);
char						**ft_split(char *str, char *c);
void						ft_putstr(char *s, int fd);
int							ft_isdigit(int c);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
char						**ft_strdup_pro(char **s);
char						*ft_strdup(const char *s);
int							ft_count_strs(char **s);
int							ft_strlen(const char *str);
long						ft_atoi(const char *nptr);
char						*ft_strjoin(char *s1, char const *s2);
char						*ft_strdup(const char *s);
size_t						ft_strlcpy(char *dst, const char *src, size_t size);

// rediction_ft
t_redirection				*ft_lstnew_redi(char *content);
void						ft_lstadd_back_redi(t_redirection **list,
								t_redirection *node);
void						ft_lstclear_redi(t_redirection **list);

// link_ft
// dbl link_ft
void						ft_dbl_lstadd_back(t_link **lst, t_link *new);
t_link						*ft_dbl_lstnew(void *content);
void						ft_dbl_lstclear(t_link **lst);

t_link						*ft_create_node(int nbr);
t_link						*ft_create_node(int nbr);
t_link						*ft_lstnew(void *content);
void						ft_lstadd_front(t_link **lst, t_link *ne);
int							ft_lstsize(t_link *lst);
t_link						*ft_lstlast(t_link *lst);
void						ft_lstadd_back(t_link **lst, t_link *ne);
void						ft_lstclear(t_link **lst);
void						ft_lstdelone(t_link *lst);
void						ft_lstiter(t_link *lst, void (*f)(void *));
t_link						*ft_lstmap(t_link *lst, void *(*f)(void *),
								void (*del)(void *));

#endif