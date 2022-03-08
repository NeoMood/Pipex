/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:05:25 by sgmira            #+#    #+#             */
/*   Updated: 2022/02/27 19:22:28 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path(char **str)
{
	int		i;
	int		j;
	int		x;
	char	*to_find;

	to_find = "PATH";
	i = 0;
	while (str[i])
	{
		j = 0;
		x = 0;
		while (to_find[j] == str[i][x])
		{
			if (str[i][j + 1] == '=')
			{
				return (&str[i][x + 2]);
			}
			j++;
			x++;
		}
		i++;
	}
	return (0);
}
