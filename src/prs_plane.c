/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:20:17 by cybourge          #+#    #+#             */
/*   Updated: 2026/05/06 13:37:41 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	process_transforms(t_prs *prs, t_obj *plane, t_pt *o, t_v4 *nrml)
{
	(void) prs;
	(void) plane;
	(void) o;
	(void) nrml;
	return (0);
}

// Parses the Plane line.
int	prs_plane(t_prs *prs, char **ltab)
{
	t_obj	plane;
	t_pt	origin;
	t_v4	normal;

	if (tab_len(ltab) != 4 && tab_len(ltab) != 5)
		return (ft_err_prt("Invalid Plane Data\n", -1));
	if (prs_v3(ltab[1], &origin, false) == -1)
		return (ft_err_prt("Invalid Plane Position\n", -1));
	if (prs_v3(ltab[1], &normal, true) == -1)
		return (ft_err_prt("Invalid Plane Normal Vector\n", -1));
	plane = pln_crt();
	if (prs_clr(ltab[3], &(plane.mtrl.clr)) == -1)
		return (ft_err_prt("Invalid Plane Color\n", -1));
	if (tab_len(ltab) == 5 && prs_mat(ltab[4], &(plane.mtrl)) == -1)
		return (ft_err_prt("Invalid Plane Material Data : ", -1));
	if (process_transforms(prs, &plane, &origin, &normal) == -1)
		return (ft_err_prt("Critical Error in Plane Transformation\n", -1));
	if (objv_add(&(prs->scn->world.objs), &plane) == -1)
		return (-1);
	return (0);
}
