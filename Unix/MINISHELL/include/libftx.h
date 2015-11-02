/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:53:56 by harar             #+#    #+#             */
/*   Updated: 2015/06/01 12:54:01 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTX_H
# define LIBFTX_H

# include <string.h>
# include <sys/stat.h>

# define RED			"\033[1;31m"
# define GREEN			"\033[1;32m"
# define CYAN			"\033[1;36m"
# define BLUE			"\033[1;34m"
# define YELLOW			"\033[1;33m"

# define X_ERR_LOC(str)	ftx_err_loc(__FILE__, __LINE__, str)

typedef struct			s_env
{
	char				*data;
	struct s_env		*next;
	struct s_env		*prev;
}						t_env;

int						ftx_err_loc(char *file, int line, char *msg);
void					ftx_putstr(char const *s);
void					ftx_putchar(char c);
int						ftx_strlen(const char *str);
void					ftx_putendl(char const *s);
void					ftx_putendl_fd(char const *s, int fd);
char					*ftx_set_var(t_env *env, char *code);
int						ftx_fprintf(int fd, char const *format, ...);
void					ftx_putchar_fd(char c, int fd);
void					ftx_putstr_color(const char *str, char *color, int i);
char					ftx_strcmp_sh(const char *s1, const char *s2, char equ);
int						ftx_strlen(const char *str);
t_env					*ftx_retenv(char **env);
void					ftx_add_elem(t_env **list, char *var_name, char *var);
void					ftx_remove_elem(t_env **list, char *value);
void					ftx_print_env(t_env *lst, char type);
char					*ftx_find_element(t_env *lst, char *value);
void					ftx_setenv_list(t_env *lst, char *var, char *value);
char					*ftx_getenv(t_env *env, char *var_name);
int						ftx_free_env(t_env *list);
char					**ft_conv_lst(t_env *env);
char					*ftx_strdup(char *src);
char					**ft_tab_var(char **arg);
char					**ft_tab_not_var(char **arg);

#endif
