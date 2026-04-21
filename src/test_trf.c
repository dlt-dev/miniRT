/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_trf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:11:33 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/15 11:29:45 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"
#include "object.h"
#include "ray.h"
/*
# define PI 3.14159265358979323846

int	main(void)
{
	t_itxv	itxv = itxv_crt(1);	
	t_obj	obj1 = sph_crt();
	t_ray	ray1 = {pt_crt(0,0,-5), v4_crt(0,0,1)};
	t_ray	ray2 = {pt_crt(0, 2, -5), v4_crt(0, 0, 1)}; // Tangent Hit on sphere
	
	if (obj_scl(&obj1, 2, 2, 2))
		printf("Error\n");
	if (obj_trl(&obj1, 0, 0, 1) == -1)
		printf("Error\n");
	if (obj_rot(&obj1, PI/2, 0, 0))
		printf("Error\n");
	if (obj_trf(&obj1))
		printf("Transformation Error\n");
	if (sph_hit(&obj1, &ray1, &itxv))
		printf("Hit 1 !\n");
	if (sph_hit(&obj1, &ray2, &itxv))
		printf("Hit 2 !\n");
	itxv_sort(&itxv);
	itxv_prt(&itxv);
	itxv_dlt(&itxv);
	return (0);
}
*/