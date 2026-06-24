/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_clr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:40:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/24 18:17:31 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

// Point is in (u,v) coordinates.
// t_clr	ftex_clr(const t_ftex *ftex, const t_pt *point)
// {
// 	int		offset;
// 	int		pixel;

// 	offset = ((point->y * ftex->w) * ftex->img.ll) + ((point->x * ftex->h) * (ftex->img.bpp / 8));
// 	pixel = *(int *)(ftex->img.addr + offset);
// 	return (clr_unpack(pixel));
// }


t_clr	ftex_clr(const t_ftex *ftex, const t_pt *point)
{
	t_clr	fcolor;

	size_t	x = floor(point->x * (ftex->w - 1));
	size_t	y = floor(point->y * (ftex->h - 1));
	//printf("%ld, %ld\n", x, y);
	char 	*dest = ftex->img.addr + x * (ftex->img.bpp / 8) + (ftex->h - y) * ftex->img.ll;
	uint32_t color = *(uint32_t *) dest;
	return (clr_unpack(color));
	// fcolor.b = (int)(color >> 16) / 255.;
	// fcolor.g = (int)(0xFF & color >> 8) / 255.;
	// fcolor.r = (int)(0xFF & color) / 255.;
	// fcolor.t = 0;
	return (fcolor);
}