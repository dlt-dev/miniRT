/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 16:24:05 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

/*
static int	raytrace(t_mlx_data *d)
{
	int			i;
	int			j;
	t_color		color;
	uint32_t	colour;

	if (d->mlx_win == NULL)
		return (1);
	if (d->update)
	{
		i = 0;
		while (i < WIN_H)
		{
			j = 0;
			while (j < WIN_W)
			{
				color.r = (double)j / (WIN_W - 1);
				color.g = (double)i / (WIN_H - 1);
				color.b = 0.6;
				color.t = 0.0;
				colour = trgb_pack(&color);
				img_pix_put(&(d->img), j, i, colour);
				j++;
				display_progress(i, j);
			}
			i++;
			usleep(3000);
		}
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.mlx_img, 0, 0);
		d->update = false;
	}
	return (0);
}
*/

static int raytrace(t_mlx_data *d)
{
	int i;
	int j;

	if (d->mlx_win == NULL)
		return (1);
	if (d->update)
	{
		j = 0;
		while (j < WIN_H)
		{
			i = 0;
			while (i < WIN_W)
			{
				t_point pixel_center = vect3_add(d->cam.p00_lc, vect3_add(vect3_mul_scalar(d->cam.pix_du, i), vect3_mul_scalar(d->cam.pix_dv, j)));
				t_vect3 ray_dir = vect3_sub(pixel_center, d->cam.cam_c);
				t_ray ray = (t_ray) {pixel_center, ray_dir};
				t_color	color = ray_color(ray);
				uint32_t colour = trgb_pack(&color);
				img_pix_put(&(d->img), i, j, colour);
				i++;
				display_progress(i, j);
			}
			j++;
		}
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.mlx_img, 0, 0);
		d->update = false;
	}
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	if (init_mlx_data(&data) < 0)
		return (1);
	data.cam = camera_setup(WIN_H, WIN_W);
	mlx_hook(data.mlx_win, DestroyNotify, 0, handle_x_button, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &raytrace, &data);
	mlx_loop(data.mlx_ptr);
	free_mlx_data(&data);
	return (0);
}
