/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lgt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:39:43 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/21 15:21:56 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

/*
int main(void)
{
	t_hit	hit1 = (t_hit)
	{
		pt_crt(0, 0, 0),
		v4_crt(0, 0, -1),
		v4_crt(0, 0, -1)
	};
	t_lgt	light1 = (t_lgt)
	{
		clr_unpack(WHITE),
		pt_crt(0, 0, -10)
	};
	t_obj	obj1 = sph_crt();
	printf("Test 1 :\n");
	t_clr res1 = obj_lgt(&obj1, &light1, &hit1);
	v4_prt((t_v4 *) &res1);

	t_hit	hit2 = (t_hit)
	{
		pt_crt(0, 0, 0),
		v4_crt(0, sqrt(2)/2.0, -sqrt(2)/2.0),
		v4_crt(0, 0, -1)
	};
	printf("Test 2 :\n");
	t_clr res2 = obj_lgt(&obj1, &light1, &hit2);
	v4_prt((t_v4 *) &res2);

	t_lgt	light2 = (t_lgt)
	{
		clr_unpack(WHITE),
		pt_crt(0, 10, -10)	
	};
	printf("Test 3 :\n");
	t_clr	res3 = obj_lgt(&obj1, &light2, &hit1);
	v4_prt((t_v4 *) &res3);

	t_hit	hit3 = (t_hit)
	{
		pt_crt(0, 0, 0),
		v4_crt(0, -sqrt(2)/2.0, -sqrt(2)/2.0),
		v4_crt(0, 0, -1)
	};
	printf("Test 4: \n");
	t_clr res4 = obj_lgt(&obj1, &light2, &hit3);
	v4_prt((t_v4 *) &res4);

	t_lgt light3 = (t_lgt)
	{
		clr_unpack(WHITE),
		pt_crt(0, 0, 10)
	};
	printf("Test 5 :\n");
	t_clr	res5 = obj_lgt(&obj1, &light3, &hit1);
	v4_prt((t_v4 *) &res5);
	
	return (0);
}
*/