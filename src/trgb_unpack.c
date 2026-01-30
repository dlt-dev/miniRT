/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_unpack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:51:51 by cybourge          #+#    #+#             */
/*   Updated: 2026/01/30 17:01:58 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_color	trgb_unpack(uint32_t packed)
{
	t_color	c;

	c.t = ((packed >> 24) & 0xFF) / 255.0;
	c.r = ((packed >> 16) & 0xFF) / 255.0;
	c.g = ((packed >> 8) & 0xFF) / 255.0;
	c.b = (packed & 0xFF) / 255.0;
	return (c);
}
