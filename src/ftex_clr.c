/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_clr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:40:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 14:16:33 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_clr	ftex_clr(const t_ftex *ftex, const t_pt *point)
{
	t_clr	fcolor;

	size_t	x = floor(point->x * (ftex->w - 1));
	size_t	y = floor(point->y * (ftex->h - 1));
	char 	*dest = ftex->img.addr + x * (ftex->img.bpp / 8) + (ftex->h - y) * ftex->img.ll;
	uint32_t color = *(uint32_t *) dest;
	return (clr_unpack(color));
	return (fcolor);
}
