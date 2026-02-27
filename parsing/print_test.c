/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:05:23 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/27 12:14:44 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_vect3(t_vect3 v) // test
{
	printf("(%.2f %.2f %.2f)", v.x, v.y, v.z);
}

void	print_color(t_color c)
{
	printf("(%.0f %.0f %.0f)", c.r, c.g, c.b); // test
}

void	print_datatest(t_rt_data *d) // test
{
	int	i;

	printf("\n===== RT DATA =====\n");
	printf("\nAmbient:\n");
	printf("  ratio: %.2f\n", d->ambient.ratio);
	printf("  color: ");
	print_color(d->ambient.color);
	printf("\n");
	printf("\nCamera:\n");
	printf("  pos: ");
	print_vect3(d->camera.camera_loc);
	printf("\n  dir: ");
	print_vect3(d->camera.orientation_vect);
	printf("\n  fov: %d\n", d->camera.fov);
	printf("\nLight:\n");
	printf("  pos: ");
	print_vect3(d->light.light_loc);
	printf("\n  ratio: %.2f\n", d->light.ratio);
	printf("  color: ");
	print_color(d->light.color);
	printf("\n");
	printf("\nObjects (%d):\n", d->obj_count);
	i = 0;
	while (i < d->obj_count)
	{
		printf("\n[%d] ", i);
		if (d->obj_tab[i].type == SPHERE)
		{
			printf("Sphere\n");
			printf("  center: ");
			print_vect3(d->obj_tab[i].u.sp.center);
			printf("\n  radius: %.2f\n", d->obj_tab[i].u.sp.radius);
			printf("  color: ");
			print_color(d->obj_tab[i].u.sp.color);
		}
		else if (d->obj_tab[i].type == PLANE)
		{
			printf("Plane\n");
			printf("  point: ");
			print_vect3(d->obj_tab[i].u.pl.center);
			printf("\n  normal: ");
			print_vect3(d->obj_tab[i].u.pl.normal);
			printf("\n  color: ");
			print_color(d->obj_tab[i].u.pl.color);
		}
		else if (d->obj_tab[i].type == CYLINDER)
		{
			printf("Cylinder\n");
			printf("  center: ");
			print_vect3(d->obj_tab[i].u.cy.center);
			printf("\n  axis: ");
			print_vect3(d->obj_tab[i].u.cy.axis);
			printf("\n  diameter: %.2f\n", d->obj_tab[i].u.cy.diameter);
			printf("  height: %.2f\n", d->obj_tab[i].u.cy.height);
			printf("  color: ");
			print_color(d->obj_tab[i].u.cy.color);
		}
		printf("\n");
		i++;
	}
	printf("\n===================\n");
}
