/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_pack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:51:03 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/04 12:24:12 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline uint32_t	trgb_pack(const t_color *c)
{
	const uint32_t	t = (uint32_t)(c->t * 255.0 + 0.5);
	const uint32_t	r = (uint32_t)(c->r * 255.0 + 0.5);
	const uint32_t	g = (uint32_t)(c->g * 255.0 + 0.5);
	const uint32_t	b = (uint32_t)(c->b * 255.0 + 0.5);

	return ((t << 24) | (r << 16) | (g << 8) | b);
}
/*
inline uint32_t	trgb_pack(const t_color *c)
{
	double			ct;
	double			cr;
	double			cg;
	double			cb;
	const uint32_t	t = (uint32_t)(ct * 255.0 + 0.5);
	const uint32_t	r = (uint32_t)(cr * 255.0 + 0.5);
	const uint32_t	g = (uint32_t)(cg * 255.0 + 0.5);
	const uint32_t	b = (uint32_t)(cb * 255.0 + 0.5);

	ct = c->t;
	cr = c->r;
	cg = c->g;
	cb = c->b;
	if (ct < 0.0)
		ct = 0.0;
	else if (ct > 1.0)
		ct = 1.0;
	if (cr < 0.0)
		cr = 0.0;
	else if (cr > 1.0)
		cr = 1.0;
	if (cg < 0.0)
		cg = 0.0;
	else if (cg > 1.0)
		cg = 1.0;
	if (cb < 0.0)
		cb = 0.0;
	else if (cb > 1.0)
		cb = 1.0;
	return ((t << 24) | (r << 16) | (g << 8) | b);
}
	*/
