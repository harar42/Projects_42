/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 15:07:26 by harar             #+#    #+#             */
/*   Updated: 2015/05/13 14:29:14 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include "libft.h"
# include "libftx.h"

char	*ft_getenv(char const *s, char **env);
char	*ft_cleanstr(char *s);
char	**ft_ret_getnext(void);
int		ft_exec_cmd(char **env, char **cmd);
char	**ft_searchpath(char *s);
char	*ft_prompt(char *path);
void	ft_printp(t_env *env2);
void	ft_env(char **cmd, t_env *env2);
void	ft_cd(char **tab, t_env *env);
void	ft_destroy_tab(char **tab);
char	*ft_check_path(char **ret, char *cmd);
int		ft_check_cmd(char *cmd);
void	ft_exec(char **cmd, t_env *env2);
void	ft_setenv(char **cmd, t_env *env2);
void	ft_unsetenv(char **cmd, t_env *env2);

#endif
