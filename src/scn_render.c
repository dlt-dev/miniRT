/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:14:29 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/03 09:16:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scn_render(t_scn *scn)
{
	t_rdr_utils	var;

	if (scn->mlx.mlx_win == NULL)
		return (-1);
	if (scn->mlx.update == false)
		return (-1);
	var.y = 0;
	while (var.y < scn->camera.vsz)
	{
		var.x = 0;
		while (var.x < scn->camera.hsz)
		{
			var.ray = cam_gen_ray(&(scn->camera), var.x, var.y);
			var.clr = wld_clr_at(&(scn->world), &(var.ray), &(scn->itxv), REC_MAX);
			img_pix_put(&(scn->mlx.img), var.x, var.y,
				clr_pack(var.clr));
			var.x++;
		}
		var.y++;
		display_progress(var.x, var.y);
	}
	mlx_put_image_to_window(scn->mlx.mlx_ptr, scn->mlx.mlx_win,
		scn->mlx.img.mlx_img, 0, 0);
	scn->mlx.update = false;
	return (0);
}
