/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_clr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:40:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/22 11:31:55 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_clr	ftex_clr(const t_ftex *ftex, const t_pt *point)
{
	int		offset;
	int		pixel;
	t_clr	color;

	
	offset = (((int)point->y % ftex->w) * ftex->img.ll) + (((int)point->x % ftex->h) * (ftex->img.bpp / 8));
	pixel = *(int *)(ftex->img.addr + offset);
	color.r = (pixel >> 16) & 0xFF;
	color.g = (pixel >> 8) & 0xFF;
	color.b = pixel & 0xFF;
	color.t = 0;
	return (color);
}
