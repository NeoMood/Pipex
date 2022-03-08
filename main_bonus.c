/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:28:13 by sgmira            #+#    #+#             */
/*   Updated: 2022/03/07 18:36:00 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	char	**paths;
	t_vars	vars;
	int		fd[2];

	vars.aca = ac - 3;
	vars.a = 2;
	vars.f1 = open(av[1], O_RDONLY, 0777);
	vars.f2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (ac > 4)
	{
		while (vars.aca)
		{
			paths = ft_split(find_path(env), ':');
			vars.cmd = ft_split(av[vars.a], ' ');
			vars.path = get_path(paths, vars.cmd);
			pipex(&vars, fd);
			free(vars.path);
			ft_free_path(vars.cmd);
			ft_free_path(paths);
			vars.a++;
			vars.aca--;
		}
	}
	else
		arg_no_err();
}
