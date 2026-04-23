/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:00:19 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 12:19:39 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"


int	main(void)
{
	t_wld	wld;
	t_ray	ray;
	t_itxv	itxv;
	t_itx	hit;

	ray = (t_ray) {.o = pt_crt(0, 0, -5), .dir = v4_crt(0,0,1)};
	wld_ini_dflt(&wld);
	itxv = itxv_crt(1);
	wld_itx(&wld, &ray, &itxv);
	hit = itxv_hit(&itxv);
	itx_cal(&hit, &ray);
	itx_prt(&hit);
	itxv_prt(&itxv);
	wld_prt(&wld);
	return (0);
}
