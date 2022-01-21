/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:23:56 by sgmira            #+#    #+#             */
/*   Updated: 2022/01/20 20:43:00 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define  PIPEX_H

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
	char	**cmd1;
	char	*path1;
	char	**cmd2;
	char	*path2;
	char	**env;
	int		f1;
	int		f2;
}	t_vars;
char	**ft_split(char const *s, char c);
char	*find_path(char **str);
char	*ft_strjoin(char	*s1, char	*s2);
size_t	ft_strlen(const char *str);
int		pipex(t_vars *vars);
char	*get_path(char	**paths, char	**cmd);
void	ft_free_path(char **paths);
char	*ft_strdup(const char *s1);
int		get_error(char *s);
int		arg_no_err(void);
int		get_error2(void);

#endif