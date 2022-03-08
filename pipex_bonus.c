/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:50:15 by sgmira            #+#    #+#             */
/*   Updated: 2022/03/07 18:33:32 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	processing_firstcmd(t_vars *vars, int *fd)
{
	dup2(vars->f1, STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(vars->path, vars->cmd, vars->env) == -1)
		get_error2();
	exit(EXIT_FAILURE);
}

void	processing_mdlcmd(t_vars *vars, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(vars->path, vars->cmd, vars->env) == -1)
		get_error2();
	exit(EXIT_FAILURE);
}

void	processing_lastcmd(t_vars *vars)
{
	dup2(vars->f2, STDOUT_FILENO);
	if (execve(vars->path, vars->cmd, vars->env) == -1)
		get_error2();
	exit(EXIT_FAILURE);
}

int	pipex(t_vars *vars, int *fd)
{
	int	pid1;

	if (pipe(fd) == -1)
		return (get_error("pipe"));
	pid1 = fork();
	if (pid1 < 0)
		return (get_error("pipe"));
	if (pid1 == 0)
	{
		if (vars->a == 2)
			processing_firstcmd(vars, fd);
		else if (vars->aca == 1)
			processing_lastcmd(vars);
		else
			processing_mdlcmd(vars, fd);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	return (0);
}
