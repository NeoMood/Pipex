/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:28:55 by sgmira            #+#    #+#             */
/*   Updated: 2022/02/27 19:23:13 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	words_count(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (i == 0 || s[i - 1] == c)
		{
			if (s[i] != c && s[i] != '\0')
				words++;
		}
		i++;
	}
	return (words);
}

static void	move_word(char *from, char *to, int start, int j)
{
	int	a;

	a = 0;
	while (j > 0)
	{
		to[a] = from[start];
		a++;
		start++;
		j--;
	}
	to[a] = '\0';
}

static void	ft_free(char **p, int a)
{
	while (a >= 0)
		free(p[--a]);
	free(p);
}

static void	ft_mallocnmove(char **p, char	*s, char c)
{
	int		i;
	int		len;
	int		a;

	i = 0;
	len = 0;
	a = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		if (len != 0)
		{
			p[a] = (char *)malloc(len + 1);
			if (p[a] == NULL)
				ft_free(p, a);
			move_word((char *)s, p[a], i, len);
			a++;
		}
		i = i + len;
	}
}

char	**ft_split(char	*s, char c)
{
	int		i;
	int		len;
	char	**p;

	i = 0;
	if (!s)
		return (NULL);
	len = words_count((char *)s, c);
	p = (char **)malloc(sizeof(char *) * (words_count((char *)s, c) + 1));
	if (p == NULL)
		return (NULL);
	ft_mallocnmove(p, s, c);
	p[len] = NULL;
	return (p);
}
