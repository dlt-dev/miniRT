/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_refraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:22:19 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/05 11:13:16 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
int	main(void)
{
	t_obj	A;
	t_obj	B;
	t_obj	C;
	t_trf	trf;
	t_ray	ray;
	t_itxv	itxv;

	A = sph_crt();
	A.mtrl.ref = 1.5;
	trf_ini(&trf);
	trf_scl(&trf, 2, 2, 2);
	trf_trf(&trf);
	obj_trf(&A, &trf);

	B = sph_crt();
	B.mtrl.ref = 2.0;
	trf_ini(&trf);
	trf_trl(&trf, 0, 0, -0.25);
	trf_trf(&trf);
	obj_trf(&B, &trf);

	C = sph_crt();
	C.mtrl.ref = 2.5;
	trf_ini(&trf);
	trf_trl(&trf, 0, 0, 0.25);
	trf_trf(&trf);
	obj_trf(&C, &trf);

	ray.o = pt_crt(0, 0, -4);
	ray.dir = v4_crt(0, 0, 1);
	
	itxv = itxv_crt(6);
	if (itxv.cap == 0)
		return (ft_err_prt("ITXV ERROR\n", 1));
	itxv.v[0].t = 2;
	itxv.v[0].obj = &A;
	itxv.v[1].t = 2.75;
	itxv.v[1].obj = &B;
	itxv.v[2].t = 3.25;
	itxv.v[2].obj = &C;
	itxv.v[3].t = 4.75;
	itxv.v[3].obj = &B;
	itxv.v[4].t = 5.25;
	itxv.v[4].obj = &C;
	itxv.v[5].t = 6.0;
	itxv.v[5].obj = &A;
	itxv.len = 6;

	for (size_t i = 0; i < itxv.len; i++)
	{
		itx_cal(&(itxv.v[i]), &ray, &itxv);
		printf("[%lu] : n1 %lf, n2 %lf\n", i, itxv.v[i].n1, itxv.v[i].n2);
	}
	
	return (0);
}
*/