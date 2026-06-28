/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:22:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/28 12:04:54 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setup_spheres(t_wld *world, t_scn *scene, size_t offset);
void	setup_planes(t_wld *world, t_scn *scene, size_t offset);
void	setup_cylinders(t_wld *world, t_scn *scene, size_t offset);

int	scn_dflt_objs(t_wld *world, t_scn *scene)
{
	const size_t	obj_nb = 9;

	world->objs = objv_crt(obj_nb);
	if (world->objs.cap == 0)
		return (-1);
	world->objs.len = obj_nb;
	setup_spheres(world, scene, 0);
	setup_planes(world, scene, 4);
	setup_cylinders(world, scene, 6);
	return (0);
}
