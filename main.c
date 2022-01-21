/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:28:13 by sgmira            #+#    #+#             */
/*   Updated: 2022/01/20 15:54:48 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char	**paths;
	t_vars	vars;
	
	if (ac == 5)
	{
		vars.f1 = open(av[1], O_RDONLY, 0777);
		vars.f2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		paths = ft_split(find_path(env), ':');
		vars.cmd1 = ft_split(av[2], ' ');
		vars.path1 = get_path(paths, vars.cmd1);
		vars.cmd2 = ft_split(av[3], ' ');
		vars.path2 = get_path(paths, vars.cmd2);
		// if (!vars.path1 && !vars.path2)
		// 	get_error("");
		pipex(&vars);
		free(vars.path1);
		free(vars.path2);
		ft_free_path(vars.cmd1);
		ft_free_path(vars.cmd2);
		ft_free_path(paths);
	}
	else
		arg_no_err();
}
