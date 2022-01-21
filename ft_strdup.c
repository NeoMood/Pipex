/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:51:45 by sgmira            #+#    #+#             */
/*   Updated: 2022/01/15 17:01:50 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	copy = (char *) malloc (sizeof (char) * ft_strlen(s1) + 1);
	if (!copy)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
