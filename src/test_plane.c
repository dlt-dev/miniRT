/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:54:41 by cybourge          #+#    #+#             */
/*   Updated: 2026/05/06 11:43:49 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "transformations.h"
#include "matrix.h"

/*
int main()
{
	t_obj	plane = pln_crt();
	t_ray	ray1 = (t_ray) {.o = pt_crt(0, -1, 0), .dir = v4_crt(0, 1, 0)};
	t_itxv	itxv = itxv_crt(2);
	t_pt	p1 = pt_crt(0, 0, 0);
	t_pt	p2 = pt_crt(10, 0, -10);
	t_pt	p3 = pt_crt(-5, 0, 150);
	t_v4	norm;

	if (pln_hit(&plane, &ray1, &itxv))
		itxv_prt(&itxv);	
	else
		printf("No Hit\n");
	pln_nrml(&plane, &p1, &norm);
	v4_prt(&norm);
	pln_nrml(&plane, &p2, &norm);
	v4_prt(&norm);
	pln_nrml(&plane, &p3, &norm);
	v4_prt(&norm);

	return (0);
}
*/