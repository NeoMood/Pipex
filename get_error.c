/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:10:22 by sgmira            #+#    #+#             */
/*   Updated: 2022/01/20 21:59:01 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_error(char *s)
{
	int i;

	i = 0;
	if(!s)
	{
		write(2, "invalid command!\n", 18);
		return(1);
	}
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(2, ": Command not found\n", 20);
		return(1);
	}
	return(1);
}
