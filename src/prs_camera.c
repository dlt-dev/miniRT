/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:18:28 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/26 10:03:43 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Initializes the camera with its fov specified in fov_str.
// Returns -1 on errors, 0 otherwise.
static int	prs_cam_init(const char *fov_str, t_cam *cam)
{
	int			dfov;
	const t_itv	fov_dbounds = {.max = 180, .min = 0.0};

	if (!is_validui(fov_str))
		return (ft_err_prt("Camera : Invalid FOV\n", -1));
	dfov = ft_atoi(fov_str);
	if (!itv_cnt(fov_dbounds, dfov))
		return (ft_err_prt("FOV needs to be between [0, 180]\n", -1));
	cam_ini(cam, WIN_W, WIN_H, dfov * (PI / 180.0));
	return (0);
}

// Returns true of the vector follows the subjects requirement :
// - its component are between [-1, 1]
// - its non null.
static bool	is_valid_orvect(t_v4 *vect)
{
	const t_itv	bounds = {.min = -1.0, .max = 1.0};
	const t_v4	nullv = v4_crt(0.0, 0.0, 0.0);

	if (v4_eql(*vect, nullv))
		return (false);
	if (!itv_cnt(bounds, vect->x))
		return (false);
	if (!itv_cnt(bounds, vect->y))
		return (false);
	if (!itv_cnt(bounds, vect->z))
		return (false);
	return (true);
}

// Parses the camera's tranformations.
// Returns -1 on errors, 0 otherwise.
static int	prs_cam_trf(char **ltab, t_cam *cam)
{
	t_pt	from;
	t_v4	dir;
	t_pt	to;
	t_pt	up;

	if (prs_v3(ltab[1], &from, false) == -1)
		return (ft_err_prt("Invalid Camera Position\n", -1));
	if (prs_v3(ltab[2], &dir, true) == -1 || !is_valid_orvect(&dir))
		return (ft_err_prt("Invalid Camera Orientation\n", -1));
	up = v4_crt(0, 1, 0);
	if (v4_eql(v4_crt(0, 0, 0), v4_xpr(up, dir)))
		up = v4_crt(1, 0, 0);
	to = v4_add(from, dir);
	m44_vtrf(&from, &to, &up, &(cam->vtf));
	if (m44_inv(&(cam->vtf), &(cam->ivtf)) == -1)
		return (ft_err_prt("Error in Camera Transformation\n", -1));
	return (0);
}

// Parses the Camera line.
// prs : parser structure that holds the scene.
// ltab : line in a string table that holds the data to be parsed.
// Returns -1 on error, 0 otherwise.
int	prs_camera(t_prs *prs, char **ltab)
{
	if (prs->cam_count > 0)
		return (ft_err_prt("Too many cameras defined\n", -1));
	if (tab_len(ltab) != 4)
		return (ft_err_prt("Wrong Camera data\n", -1));
	if (prs_cam_init(ltab[3], &(prs->scn->camera)) == -1)
		return (-1);
	if (prs_cam_trf(ltab, &(prs->scn->camera)) == -1)
		return (-1);
	prs->cam_count++;
	return (0);
}
