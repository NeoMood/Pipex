/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:19:28 by sgmira            #+#    #+#             */
/*   Updated: 2022/02/08 18:07:41 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char	**paths, char	**cmd)
{
	char	*path;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (paths[i])
	{
		path = ft_strdup(paths[i]);
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, cmd[0]);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	get_error(cmd[0]);
	return (0);
}
