/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validclr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:15:21 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:15:27 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Returns true if the fields of the array properly define a color.
// ie : tab = {int, int, int} with int in [0,255].
bool	is_validclr(char **tab)
{
	const t_itv		bounds = {.max = 255, .min = 0};
	const size_t	len = tab_len(tab);
	size_t			i;

	i = 0;
	while (i < len)
	{
		if (!is_validui(tab[i]) || !itv_cnt(bounds, ft_atoi(tab[i])))
			return (false);
		i++;
	}
	return (true);
}
