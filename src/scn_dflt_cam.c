/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:30:21 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 12:36:15 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scn_dflt_cam(t_cam *camera)
{
	const t_pt	from = pt_crt(0, 0, -5);
	const t_pt	to = pt_crt(0, 0, 1);
	t_v4		up;

	up = v4_crt(0, 1, 0);
	cam_ini(camera, WIN_W, WIN_H, PI / 3.0);
	m44_vtrf(&from, &to, &up, &(camera->vtf));
	m44_inv(&(camera->vtf), &(camera->ivtf));
	return (0);
}
