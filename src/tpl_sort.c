/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:16:55 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 10:20:13 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	tpl_sort(t_tpl *tuple)
{
	double	tmp;

	if (tuple->x > tuple->y)
	{
		tmp = tuple->y;
		tuple->y = tuple->x;
		tuple->x = tmp;
	}
}
