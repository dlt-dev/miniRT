/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:00:17 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 13:06:21 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	ray_trf(const t_ray *ray, const t_m44 *m1, t_ray *res)
{
	if (!ray || !m1 || ! res)
		return (-1);
	if (m44_vprd(m1, &(ray->dir), &(res->dir)) == -1)
		return (-1);
	if (m44_vprd(m1, &(ray->o), &(res->o)) == -1)
		return (-1);
	return (0);
}
