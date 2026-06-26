/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:11:32 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/26 09:53:16 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"
# include "textures.h"
# include <stdio.h>

// Material for a Phong Lighting model.
// clr	: Colour
// amb	: Ambient light reflection
// dif	: Diffuse reflection
// spc	: Specular reflection
// shi	: Shininess 
// rfl	: Reflection 0 = no reflect 1.0 = full reflect
// tsp	: Transparency
// ref	: Refraction
typedef struct s_material
{
	t_clr	clr;
	double	amb;
	double	dif;
	double	spc;
	double	shi;
	double	rfl;
	double	tsp;
	double	ref;
	t_tex	*tex;
	t_m44	tm;
	t_m44	itm;
	t_tex	*hmap;
}	t_mtl;

// Sets the value of a material to default values.
void	mtl_ini(t_mtl *mtl);

// Applies the transformations to the material.
int		mtl_trf(t_mtl *mtl, t_trf *trf);

// Displays the material on stdout.
void	mtl_prt(const t_mtl *mtl);

#endif