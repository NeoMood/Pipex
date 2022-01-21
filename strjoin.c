/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:36:01 by sgmira            #+#    #+#             */
/*   Updated: 2022/01/16 18:49:37 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char	*s1, char	*s2)
{
	int		i;
	int		l1;
	int		l2;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	joined = (char *) malloc (sizeof (char) * (l1 + l2) + 1);
	i = -1;
	if (!joined)
		return (0);
	while (s1[++i])
		joined[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		joined[l1 + i] = s2[i];
		i++;
		l2++;
	}
	free (s1);
	joined[l1 + i] = '\0';
	return (joined);
}
