/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:11:32 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 13:21:32 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"
# include "pattern.h"

// Material for a Phong Lighting model.
typedef struct s_material
{
	t_clr	clr;
	double	amb;
	double	dif;
	double	spc;
	double	shi;
	t_pat	pat;
}	t_mtl;

// Sets the value of a material to default values.
void	mtl_ini(t_mtl *mtl);

#endif