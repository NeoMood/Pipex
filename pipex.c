/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:50:15 by sgmira            #+#    #+#             */
/*   Updated: 2022/01/20 20:43:34 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	processing_cmd1(t_vars *vars, int *fd)
{
	dup2(vars->f1, STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if(execve(vars->path1, vars->cmd1, vars->env) == -1)
		get_error2();
	exit(EXIT_FAILURE);
}

void	processing_cmd2(t_vars *vars, int *fd)
{
	dup2(vars->f2, STDOUT_FILENO);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if(execve(vars->path2, vars->cmd2, vars->env) == -1)
		get_error2();
	exit(EXIT_FAILURE);
}

int	pipex(t_vars *vars)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		return (get_error("pipe"));
	pid1 = fork();
	if (pid1 < 0)
		return (get_error("pipe"));
	if (pid1 == 0)
		processing_cmd1(vars, fd);
	pid2 = fork();
	if (pid2 < 0)
		return (get_error("pipe"));
	if (pid2 == 0)
		processing_cmd2(vars, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
