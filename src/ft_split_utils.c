/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:35:56 by jdelattr          #+#    #+#             */
/*   Updated: 2026/06/26 17:46:47 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_count(char const *s, char *sep)
{
	int	i;
	int	wordcount;
	int	inword;

	i = 0;
	wordcount = 0;
	inword = 0;
	while (s[i])
	{
		if (is_sep(s[i], sep) == 0)
			inword = 0;
		else if (is_sep(s[i], sep) != 0)
		{
			if (inword == 0)
				wordcount++;
			inword = 1;
		}
		i++;
	}
	return (wordcount);
}

char	**ft_allocsplit(int wordcount)
{
	int		i;
	char	**split;

	i = 0;
	split = malloc(sizeof(char *) * (wordcount + 1));
	if (!split)
		return (NULL);
	while (i < (wordcount + 1))
	{
		split[i] = NULL;
		i++;
	}
	return (split);
}

char	**ft_freesplit(char **split, int j)
{
	while (j > 0)
	{
		j--;
		free(split[j]);
	}
	free(split);
	return (0);
}

char	**ft_fillsplit(char **split, char const *s, char *sep)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], sep) == 0)
			i++;
		start = i;
		while (s[i] && is_sep(s[i], sep) != 0)
			i++;
		if (i > start)
		{
			split[j] = ft_substr(s, start, i - start);
			if (split[j] == 0)
				return (ft_freesplit(split, j));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}
