/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:50:40 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 13:46:29 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

# include "transformations.h"

void	pt_display(const t_pt *p)
{
	printf("(%3f, %3f, %3f, %3f)\n", p->x, p->y, p->z, p->w);
}

int main()
{
	t_pt origin = pt_crt(1.0, 2.0, 3.0);
	t_v4 dir = v4_crt(0.0, 1.0, 0.0);
	t_ray ray = (t_ray){origin, dir};
	
	// t_pt pos0 = ray_pos(&ray, 0);
	// t_pt pos1 = ray_pos(&ray, 1);
	// t_pt pos2 = ray_pos(&ray, -1);
	// t_pt pos3 = ray_pos(&ray, 2.5);
	// pt_display(&pos0);
	// pt_display(&pos1);
	// pt_display(&pos2);
	// pt_display(&pos3);

	t_m44	trl;
	m44_trl(3.0, 4.0, 5.0, &trl);
	t_ray trf;
	ray_trf(&ray, &trl, &trf);
	ray_prt(&trf);

	t_m44	scl;
	m44_scl(2, 3, 4, &scl);
	t_ray	trf2;
	ray_trf(&ray, &scl, &trf2);
	ray_prt(&trf2);
}
*/