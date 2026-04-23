/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:11:32 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 13:59:43 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

// Material for a Phong Lighting model.
typedef struct s_material
{
	t_clr	clr;
	double	amb;
	double	dif;
	double	spc;
	double	shi;
}	t_mtl;

#endif