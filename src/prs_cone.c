/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:07:18 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 11:50:04 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	process_transforms(t_obj *cone, t_cyldata *data)
{
	const t_v4	basev = v4_crt(0, 1, 0);
	t_trf		trfs;

	trf_ini(&trfs);
	if (trf_trl(&trfs, data->c.x, data->c.y, data->c.z) == -1)
		return (-1);
	// if (m44_rotm(&(data->ax), &(trfs.rotm), &(trfs.irotm)) == -1)
	// 	return (-1);
	if (m44_vrv(&basev, &(data->ax), &(trfs.rotm)) == -1)
		return (-1);
	if (m44_inv_rot(&(trfs.rotm), &(trfs.irotm)) == -1)
		return (-1);
	if (trf_scl(&trfs, data->rad, data->h, data->rad) == -1)
		return (-1);
	if (trf_trf(&trfs) == -1)
		return (-1);
	if (obj_trf(cone, &trfs) == -1)
		return (-1);
	return (0);
}

// Parses the Cone line.
// prs : parser structure that holds the scene.
// ltab : line in a string table that holds the data to be stored.
// Returns -1 on errors, 0 otherwise.
int	prs_cone(t_prs *prs, char **ltab)
{
	t_obj		cone;
	t_cyldata	data;

	if (tab_len(ltab) != 6 && tab_len(ltab) != 7)
		return (ft_err_prt("Invalid Cone Data\n", -1));
	if (prs_v3(ltab[1], &(data.c), false) == -1)
		return (ft_err_prt("Invalid Cone Center\n", -1));
	if (prs_v3(ltab[2], &(data.ax), true) == -1)
		return (ft_err_prt("Invalid Cone Axis\n", -1));
	if (!is_validf(ltab[3]))
		return (ft_err_prt("Invalid Cone Diameter\n", -1));
	data.rad = ft_atof(ltab[3]) / 2.0;
	if (data.rad <= 0)
		return (ft_err_prt("Cone Radius Must be > 0\n", -1));
	if (!is_validf(ltab[4]))
		return (ft_err_prt("Invalid Cone Height\n", -1));
	data.h = ft_atof(ltab[4]);
	if (data.h <= 0)
		return (ft_err_prt("Cone Height must be > 0\n", -1));
	cone = con_crt();
	if (prs_clr(ltab[5], &(cone.mtrl.clr)) == -1)
		return (ft_err_prt("Invalid Cone Color\n", -1));
	if (tab_len(ltab) == 7 && prs_mat(ltab[6], &(cone.mtrl)) == -1)
		return (ft_err_prt("Invalid Cone Material Data : ", -1));
	if (process_transforms(&cone, &data) == -1)
		return (ft_err_prt("Critical Error in Cone Transformations\n", -1));
	if (objv_add(&(prs->scn->world.objs), &cone) == -1)
		return (ft_err_prt("Could not add Cone to World\n", -1));
	return (0);
}
