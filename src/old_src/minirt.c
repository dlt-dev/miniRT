/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/25 14:05:03 by cybourge         ###   ########.fr       */
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

static t_ray	create_ray(t_mlx_data *data, int i, int j)
{
	t_point	pixel_center = vect3_add(data->cam.p00_lc, vect3_add(vect3_mul_scalar(data->cam.pix_du, i), vect3_mul_scalar(data->cam.pix_dv, j)));
	return ((t_ray) {
		pixel_center,
		vect3_unit(vect3_sub(pixel_center, data->cam.cam_c))
	});
}

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
				t_ray ray = create_ray(d, i, j);
				t_color	color = ray_color(ray, d);
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

static t_cldr	cldr_create(t_point point, t_vect3 axis, double d, double h)
{
	t_cldr cyl;

	cyl.c = point;
	cyl.axis = vect3_unit(axis);
	cyl.r = d / 2.0;
	cyl.h = h;
	cyl.capt = vect3_add(cyl.c, vect3_mul_scalar(cyl.axis, h / 2.0));
	cyl.capb = vect3_sub(cyl.c, vect3_mul_scalar(cyl.axis, h / 2.0));
	cyl.color = trgb_unpack(0x0029FB44);
	return (cyl);
}

int	main(void)
{
	t_mlx_data	data;

	if (init_mlx_data(&data) < 0)
		return (1);
	srand(time(NULL));
	data.cam = camera_setup(WIN_H, WIN_W);
	data.sphere[0] = (t_sphere) {(t_vect3) {0.0, 0.0, -5.0}, 0.01, trgb_unpack(0x00FFFFFF)}; // white
	data.sphere[1] = (t_sphere) {(t_vect3) {0.0, 0.0, -5.0}, 0.1, trgb_unpack(0x002E28FE)}; // blue
	data.sphere[2] = (t_sphere) {(t_vect3) {0.0, 1.0, -4.0}, 0.1, trgb_unpack(0x00FB2617)}; // red
	data.sphere[3] = (t_sphere) {(t_vect3) {1.0, 0.0, -4.0}, 0.1, trgb_unpack(0x00FBF522)}; // yellow
	data.sphere[4] = (t_sphere) {(t_vect3) {0.0, 0.0, -10.0}, 2.5, trgb_unpack(0x00000000)}; // black
	data.cylinder = cldr_create((t_point ) {-5.0, 0.0, -10.0}, (t_vect3) {0.0, 0.0, -0.5}, 10.0, 10.0); // green
	data.plane = (t_pln) {(t_point) {0.0, -1.0, -3.0}, vect3_unit((t_vect3) {0.0, 1.0, 0.0}), trgb_unpack(0x00FFFFFF)};
	//data.plane = (t_pln) {data.cylinder.capt, data.cylinder.axis, trgb_unpack(0x00FFFFFF)};
	data.cone = (t_cone) {(t_point) {3.0, 0.0, -5.0}, (t_point) {4.0, 0, -5.0}, 3.0, trgb_unpack(0x00FF2EF5)}; // pink
	data.triangle = (t_trgl) {(t_point) {1.0, 1.5, -4.0}, (t_point) {1.5, 2.0, -4.0}, (t_point) {-1.5, 2.0, -4.0},trgb_unpack(0x001FF8FF)};
	mlx_hook(data.mlx_win, DestroyNotify, 0, handle_x_button, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &raytrace, &data);
	mlx_loop(data.mlx_ptr);
	free_mlx_data(&data);
	return (0);
}
