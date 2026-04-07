/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:46:01 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 15:34:41 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "object.h"
#include "color.h"
#include "ray.h"
#include "vector4.h"
#include "transformations.h"

static void	display_sphere(const t_sph *sp)
{
	printf("Sphere : ({%f, %f, %f, %f}, %f)\n",
		sp->c.x, sp->c.y, sp->c.z, sp->c.w,
		sp->r
		);
	m44_prt(&(sp->tm));
}

int main()
{
	t_objv	objv = objv_crt(2);
	if (!(objv.v))
		return (1);
	t_itxv	itxv = itxv_crt(1);
	if (!(itxv.v))
		return (1);
	t_obj	obj1 = {SPHERE, {sph_crt()}};
	t_obj	obj2 = {SPHERE, {sph_crt()}};
	t_obj	obj3 = {SPHERE, {sph_crt()}};
	t_obj	obj4 = {SPHERE, {sph_crt()}};
	t_ray	ray1 = {pt_crt(0, 0, -5), v4_crt(0, 0, 1)}; // Double Hit
	//t_ray	ray2 = {pt_crt(0, 1, -5), v4_crt(0, 0, 1)}; // Tangent Hit
	t_ray	ray3 = {pt_crt(0, 2, -5), v4_crt(0, 0, 1)}; // Miss
	t_ray	ray4 = {pt_crt(0, 0, 0), v4_crt(0, 0, 1)};	// Single Hit from inside.
	
	display_sphere(&(obj1.u_o.sp));
	m44_scl(2, 2, 2, &(obj1.u_o.sp.tm));
	display_sphere(&(obj1.u_o.sp));
	
	m44_trl(2, 3, 4, &(obj2.u_o.sp.tm));
	
	if (sph_hit(&obj1, &ray1, &itxv))
		printf("Hit 1!\n");
	else
		printf("Missed 1!\n");
	if (sph_hit(&obj2, &ray1, &itxv))
		printf("Hit 2!\n");
	else
		printf("Missed 2!\n");
	if (sph_hit(&obj3, &ray3, &itxv))
		printf("Hit 3!\n");
	else
		printf("Missed 3!\n");
	if (sph_hit(&obj4, &ray4, &itxv))
		printf("Hit 4!\n");
	else
		printf("Missed 4!\n");
	itxv_sort(&itxv);
	itxv_prt(&itxv);
	t_itx	real_hit = itxv_hit(&itxv);
	printf("We hit at %f\n", real_hit.t);
	objv_add(&objv, &obj1);
	objv_add(&objv, &obj2);
	objv_add(&objv, &obj3);
	objv_add(&objv, &obj4);
	objv_prt(&objv);
	itxv_dlt(&itxv);
	objv_dlt(&objv);
}