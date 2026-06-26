/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:02:02 by jdelattr          #+#    #+#             */
/*   Updated: 2026/06/26 17:36:38 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char const *s, char *sep)
{
	char	**split;
	int		wordcount;

	if (s == NULL)
		return (NULL);
	wordcount = ft_count(s, sep);
	split = ft_allocsplit(wordcount);
	if (!split)
		return (NULL);
	split = ft_fillsplit(split, s, sep);
	return (split);
}
