/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_pack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:51:03 by cybourge          #+#    #+#             */
/*   Updated: 2026/01/30 17:01:46 by cybourge         ###   ########.fr       */
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
