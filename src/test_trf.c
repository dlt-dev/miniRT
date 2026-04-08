/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_trf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:11:33 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/08 12:46:21 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "transformations.h"
#include "object.h"
#include "ray.h"

# define PI 3.14159265358979323846

int	main(void)
{
	// t_itxv	itxv = itxv_crt(1);	
	// t_obj	obj1 = sph_crt();
	// t_ray	ray1 = {pt_crt(0,0,-5), v4_crt(0,0,1)};
	//t_ray	ray2 = {pt_crt(0, 1, -5), v4_crt(0, 0, 1)}; // Tangent Hit on unit sphere
	
	// if (obj_trl(&obj1, 0, 0, 1) == -1)
	// 	printf("Error\n");
	// if (obj_rot(&obj1, -51, 10, 1))
	// 	printf("Error\n");
	// if (obj_scl(&obj1, 2, 2, 2))
	// 	printf("Error\n");

	t_m44 mat = {
		0, 0, 0.000000058, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};
	m44_prt(&mat);
	// if (sph_hit(&obj1, &ray1, &itxv))
	// 	printf("Hit 1 !\n");
	// itxv_prt(&itxv);
	// itxv_dlt(&itxv);
	return (0);
}
