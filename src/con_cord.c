/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:57:22 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 16:59:07 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_pt	con_cord(const t_pt *point)
{
	t_pt	uv;
	double	theta;
	double	radius;

	radius = point->x * point->x + point->z * point->z;
	theta = atan2(point->x, point->z);
	uv.x = 1 - ((theta / (2 * PI)) + 0.5);
	uv.y = fmod(sqrt(radius), 1);
	uv.z = 0.0;
	uv.w = 1.0;
	return (uv);
}