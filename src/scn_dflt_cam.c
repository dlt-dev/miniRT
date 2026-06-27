/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:30:21 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:59:32 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scn_dflt_cam(t_cam *camera)
{
	const t_pt	from = pt_crt(12.5, 1.0, -20);
	const t_v4	dir = v4_crt(0, 0, 1);
	const t_pt	to = v4_add(from, dir);
	const t_pt	up = v4_crt(0, 1, 0);

	cam_ini(camera, WIN_W, WIN_H, 70 * (PI / 180.0));
	m44_vtrf(&from, &to, &up, &(camera->vtf));
	m44_inv(&(camera->vtf), &(camera->ivtf));
	return (0);
}
