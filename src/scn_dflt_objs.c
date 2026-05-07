/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:22:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/05/06 13:57:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Utility Function that sets up the Floor, Left Wall and Right Wall.
// Sphere 1 setup : The Floor
// Sphere 2 Setup : Left Wall
// Sphere 3 Setup : Right Wall
static void	setup_bg(t_wld *world)
{
	world->objs.v[0] = pln_crt();
	obj_trf(&(world->objs.v[0]));
	world->objs.v[0].mtrl.clr = clr_unpack(WHITE);
	world->objs.v[0].mtrl.spc = 0.1;
	world->objs.v[1] = pln_crt();
	obj_rot(&(world->objs.v[1]), PI / 2.0, -PI / 4.0, 0.0);
	obj_trl(&(world->objs.v[1]), 0, 0, 5);
	obj_trf(&(world->objs.v[1]));
	world->objs.v[1].mtrl.clr = clr_unpack(BLUE);
	world->objs.v[1].mtrl.spc = 0.1;
	world->objs.v[2] = pln_crt();
	obj_rot(&(world->objs.v[2]), PI / 2.0, PI / 4.0, 0.0);
	obj_trl(&(world->objs.v[2]), 0, 0, 5);
	obj_trf(&(world->objs.v[2]));
	world->objs.v[2].mtrl.clr = clr_unpack(RED);
	world->objs.v[2].mtrl.spc = 0.1;
}

// Utility function that sets up the Middle, Left and Right Spheres.
// Sphere 4 Setup : Middle Sphere
// Sphere 5 Setup : Right Sphere
// Sphere 6 Setup : Left Sphere
static void	setup_ele(t_wld *world, size_t offset)
{
	world->objs.v[offset + 0] = sph_crt();
	obj_trl(&(world->objs.v[offset + 0]), -0.5, 1.0, 0.5);
	obj_trf(&(world->objs.v[offset + 0]));
	world->objs.v[offset + 0].mtrl.clr = clr_unpack(0x00db1230);
	world->objs.v[offset + 0].mtrl.dif = 0.7;
	world->objs.v[offset + 0].mtrl.spc = 0.3;
	world->objs.v[offset + 0].mtrl.shi = 10;
	world->objs.v[offset + 1] = sph_crt();
	obj_scl(&(world->objs.v[offset + 1]), 0.5, 0.5, 0.5);
	obj_trl(&(world->objs.v[offset + 1]), 1.5, 0.5, -0.5);
	obj_trf(&(world->objs.v[offset + 1]));
	world->objs.v[offset + 1].mtrl.clr = clr_unpack(0x00db2834);
	world->objs.v[offset + 1].mtrl.dif = 0.5;
	world->objs.v[offset + 1].mtrl.spc = 0.9;
	world->objs.v[offset + 2] = sph_crt();
	obj_trl(&(world->objs.v[offset + 2]), -1.5, 0.33, -0.75);
	obj_scl(&(world->objs.v[offset + 2]), 0.33, 0.33, 0.33);
	obj_trf(&(world->objs.v[offset + 2]));
	world->objs.v[offset + 2].mtrl.clr = clr_unpack(0x00db3012);
	world->objs.v[offset + 2].mtrl.dif = 0.9;
	world->objs.v[offset + 2].mtrl.spc = 0.9;
	world->objs.v[offset + 2].mtrl.shi = 1000000;
}

int	scn_dflt_objs(t_wld *world)
{
	world->objs = objv_crt(6);
	if (world->objs.cap == 0)
		return (-1);
	world->objs.len = 6;
	setup_bg(world);
	setup_ele(world, 3);
	return (0);
}
