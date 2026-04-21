/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_normals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:18:04 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/21 13:06:21 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	main(void)
{
	t_obj	obj1 = sph_crt();
	t_obj	obj2 = sph_crt();
	t_pt	pt1 = pt_crt(0, 1.70711, -0.70711);
	t_pt	pt2 = pt_crt(0.0, sqrt(2)/2.0, -sqrt(2)/2.0);
	t_v4	n1;
	t_v4	n2;

	obj_trl(&obj1, 0, 1, 0);
	obj_trf(&obj1);
	obj_rot(&obj2, 0.0, 0.0, PI/5);
	obj_scl(&obj2, 1.0, 0.5, 1.0);
	obj_trf(&obj2);
	if (sph_nrml(&obj1, &pt1, &n1) == -1)
		printf("Error\n");
	if (sph_nrml(&obj2, &pt2, &n2) == -1)
		printf("Error\n");
	if (!deql(v4_len(n1), 1.0))
		printf("Not Normed");
	if (!deql(v4_len(n2), 1.0))
		printf("Not Normed");
	v4_prt(&n1);
	v4_prt(&n2);
	return (0);
}