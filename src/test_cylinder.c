/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:58 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/16 16:40:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
int	main()
{
	t_obj	cylinder = cld_crt();
	t_ray	ray;
	t_itxv	itxv;

	itxv = itxv_crt(2);
	if (itxv.cap == 0)
		return (1);

	// Truncated Cylinders
	// ray = (t_ray){.o = pt_crt(0,1.5,0), .dir = v4_uni(v4_crt(0.1,1,0))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,3,-5), .dir = v4_uni(v4_crt(0,0,1))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,0,-5), .dir = v4_uni(v4_crt(0,0,1))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,2,-5), .dir = v4_uni(v4_crt(0,0,1))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,1,-5), .dir = v4_uni(v4_crt(0,0,1))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,1.5,-2), .dir = v4_uni(v4_crt(0,0,1))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// printf("\n");

	// END CAPS
	// ray = (t_ray){.o = pt_crt(0,3,0), .dir = v4_uni(v4_crt(0,-1,0))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,3,-2), .dir = v4_uni(v4_crt(0,-1,2))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,4,-2), .dir = v4_uni(v4_crt(0,-1,1))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,0,-2), .dir = v4_uni(v4_crt(0,1,2))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,-1,-2), .dir = v4_uni(v4_crt(0,1,1))};
	// cld_hit(&cylinder, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// printf("\n");

	// Normal Vectors
	t_v4 	nvect;
	t_pt	point;
	
	point = pt_crt(0,1,0);
	cld_nrml(&cylinder, &point, &nvect);
	v4_prt(&nvect);
	point = pt_crt(0.5,1,0);
	cld_nrml(&cylinder, &point, &nvect);
	v4_prt(&nvect);
	point = pt_crt(0,1,0.5);
	cld_nrml(&cylinder, &point, &nvect);
	v4_prt(&nvect);
	point = pt_crt(0,2,0);
	cld_nrml(&cylinder, &point, &nvect);
	v4_prt(&nvect);
	point = pt_crt(0.5,2,0);
	cld_nrml(&cylinder, &point, &nvect);
	v4_prt(&nvect);
	point = pt_crt(0,2,0.5);
	cld_nrml(&cylinder, &point, &nvect);
	v4_prt(&nvect);
	
	itxv_prt(&itxv);
	itxv_dlt(&itxv);
	return (0);
}
*/