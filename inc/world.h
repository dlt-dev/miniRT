/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:37:45 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:27:38 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "object.h"
# include "light.h"
# include <stdio.h>

// Structure that holds the objects and light of a scene
// objs : geometric object vector
// lgts : lights
typedef struct	s_world
{
	t_objv	objs;
	t_lgtv	lgts;
}	t_wld;

// Initilizes a world defined by default.
int		wld_ini_dflt(t_wld *wld);

// Deletes a world and its components
void	wld_dlt(t_wld *wld);

// Displays a world
void	wld_prt(const t_wld *wld);

// Adds an object to the world.
// Returns -1 on error, 0 otherwise.
int		wld_add_obj(t_wld *wld, const t_obj *obj);

// Adds a light to the world.
// Returns -1 on error, 0 otherwise.
int		wld_add_lgt(t_wld *wld, const t_lgt *light);

// Writes the intersections of ray with world in inter.
// Returns -1 on error, 0 otherwise.
int		wld_itx(const t_wld *world, const t_ray *ray, t_itv *itxv);






#endif