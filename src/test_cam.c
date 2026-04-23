/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:10:29 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 15:23:59 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transformations.h"

int	main(void)
{
	t_m44	view;
	t_m44	model;
	t_v4	from = pt_crt(0,0,0);
	t_v4	to = pt_crt(0,0,-1);
	t_v4	up = v4_crt(0, 1, 0);

	m44_vtrf(&from, &to, &up, &view);
	m44_idm(&model);
	m44_prt_uop(&view, &model, "Equality");
	
	from = pt_crt(0,0,0);
	to = pt_crt(0,0,1);
	up = v4_crt(0,1,0);
	m44_vtrf(&from, &to, &up, &view);
	m44_scl(-1, 1, -1, &model);
	m44_prt_uop(&view, &model, "Equality");

	from = pt_crt(0,0,8);
	to = pt_crt(0,0,0);
	up = v4_crt(0,1,0);
	m44_vtrf(&from, &to, &up, &view);
	m44_trl(0, 0, -8, &model);
	m44_prt_uop(&view, &model, "Equality");
	
	from = pt_crt(1,3,2);
	to = pt_crt(4,-2,8);
	up = v4_crt(1,1,0);
	m44_vtrf(&from, &to, &up, &view);
	m44_prt(&view);
	return (0);
}