/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:19:34 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 08:07:07 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Parses the Sphere line.
// prs : parser structure that holds the scene.
// ltab : line in a string table that holds the data to be stored.
// Returns -1 on errors, 0 otherwise.
int	prs_sphere(t_prs *prs, char **ltab)
{
	t_obj	sphere;
	t_pt	center;
	double	radius;

	if (tab_len(ltab) != 4)
	{
		printf("Invalid Sphere Data\n");
		return (-1);
	}
	if (prs_v3(ltab[1], &center, false) == -1)
	{
		printf("Invalid Sphere Position\n");
		return (-1);
	}
	if (!is_validf(ltab[2]))
	{
		printf("Invalid Sphere Radius\n");
		return (-1);
	}
	radius = ft_atof(ltab[2]) / 2.0;
	if (radius <= 0.0)
	{
		printf("Sphere Radius Must be Positive\n");
		return (-1);
	}
	sphere = sph_crt();
	if (prs_clr(ltab[3], &(sphere.mtrl.clr)) == -1)
	{
		printf("Invalid Sphere Color\n");
		return (-1);
	}
	if (obj_trl(&sphere, center.x, center.y, center.z) == -1)
		return (-1);
	if (obj_scl(&sphere, radius, radius, radius) == -1)
		return (-1);
	if (obj_trf(&sphere) == -1)
		return (-1);
	if (objv_add(&(prs->scn->world.objs), &sphere) == -1)
		return (-1);
	return (0);
}
