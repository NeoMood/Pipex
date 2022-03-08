/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:23:56 by sgmira            #+#    #+#             */
/*   Updated: 2022/03/07 16:46:42 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define  PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <errno.h>
# include <string.h>

typedef struct s_vars
{
	char		**cmd;
	char		*path;
	char		**env;
	int			f1;
	int			f2;
	int			a;
	int			aca;
	int			fd[2];
}	t_vars;

char	**ft_split(char	*s, char c);
char	*find_path(char **str);
char	*ft_strjoin(char	*s1, char	*s2);
int		ft_strlen( char *str);
int		pipex(t_vars *vars, int *fd);
char	*get_path(char	**paths, char	**cmd);
void	ft_free_path(char **paths);
char	*ft_strdup( char *s1);
int		get_error(char *s);
int		arg_no_err(void);
int		get_error2(void);
int		ft_strcmp(char *s1, char *s2);
char	*here_doc(char **av);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_strchr( char *s, int c);
char	*get_next_line(int fd);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strtrim(char *s1, char *set);
void	ft_putstr_fd(char *s, int fd);
int		heredoc_paths(char	**av, char **env, int f2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif