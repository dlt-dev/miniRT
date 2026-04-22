/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itx_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 08:12:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 08:17:39 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int	itx_ini(t_itx *itx, const t_ray *ray)
{
	if (!itx || !(itx->obj))
		return (-1);
	itx->hp = ray_pos(ray, itx->t);
	itx->rd = v4_inv(ray->dir);
	return (0);
}
