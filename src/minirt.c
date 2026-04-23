/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:55:22 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

/*
static t_clr	test_colors(int i, int j)
{
	const t_clr		color1 = clr_unpack(0x00ffbb00);
	const t_clr		color2 = clr_unpack(0x0015965D);
	t_clr			color3;

	if (i > WIN_H / 2 && j > WIN_W / 2)
		color3 = color1;
	else if (i > WIN_H / 2 && j <= WIN_W / 2)
		color3 = color2;
	else
		color3 = clr_bld(color1, color2);
	return (color3);
}
	
static int	raytrace(t_mlx_data *d)
{
	int		i;
	int		j;
	t_clr	color;

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
				color = test_colors(i, j);
				img_pix_put(&(d->img), j, i, clr_pack(color));
				j++;
				display_progress(i, j);
			}
			i++;
		}
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.mlx_img, 0, 0);
		d->update = false;
	}
	return (0);
}
*/


typedef struct	s_simple_scene
{
	t_pt	ro;		// Ray origin.
	double	wall_z;	// Wall's distance along the z axis.
	double	wall_s;	// Wall's size.
	int		cvs_px;	// Canvas pixels count.
	double	px_siz;	// Pixel size.
	double	half;	// Midpoint on the wall.
	t_obj	obj1;	// Object we want to draw.
}	t_ssc;

static int	draw_simple_scene(t_mlx_data *data)
{
	t_ssc	scene;
	int		x;
	int		y;
	double	world_y;
	double	world_x;
	t_v4	position;
	t_ray	ray;
	t_lgt	light;
	t_itxv	itxv;

	if (data->mlx_win == NULL)
		return (1);
	if (data->update == false)
		return (1);
	scene.ro = pt_crt(0, 0, -5);
	scene.wall_z = 10;
	scene.wall_s = 7;
	scene.cvs_px = WIN_H;
	scene.px_siz = scene.wall_s / scene.cvs_px;
	scene.half = scene.wall_s / 2.0;
	scene.obj1 = sph_crt();
	scene.obj1.mtrl.clr = clr_unpack(0x001F31FF); //(t_clr) {0.0, 1.0, 0.2, 1.0};

	light.pos = pt_crt(-10, 10, -10);
	light.clr = clr_unpack(WHITE);

	itxv = itxv_crt(2);
	
	obj_trl(&(scene.obj1), 1, 0, 2);
	obj_rot(&(scene.obj1), 3, 4, 6);
	obj_scl(&(scene.obj1), 0.5, 0.5, 0.5);
	obj_she(&(scene.obj1), (t_spara){1,0,0,0,0,0});
	obj_trl(&(scene.obj1), -1, 0, -2);
	obj_trf(&(scene.obj1));
	y = 0;
	while (y < WIN_H)
	{
		world_y = scene.half - scene.px_siz * y;
		x = 0;
		while (x < WIN_W)
		{
			world_x = -scene.half + scene.px_siz * x;
			position = v4_crt(world_x, world_y, scene.wall_s);
			ray = (t_ray){scene.ro, v4_uni(v4_sub(position, scene.ro))};
			if (sph_hit(&(scene.obj1), &ray, &itxv))
			{
				itxv_sort(&itxv);
				t_itx	itx = itxv_hit(&itxv);
				itx_ini(&itx, &ray);
				sph_nrml(itx.obj, &(itx.hp), &(itx.nrm));
				t_clr	clr = obj_lgt(itx.obj, &light, &itx);
				img_pix_put(&(data->img), x, y, clr_pack(clr));
				itxv_clr(&itxv);
			}
			else
				img_pix_put(&(data->img), x, y, BLACK);
			x++;
			display_progress(x, y);
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.mlx_img, 0, 0);
	data->update = false;
	itxv_dlt(&itxv);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	if (init_mlx_data(&data) < 0)
		return (1);
	srand(time(NULL));
	mlx_hook(data.mlx_win, DestroyNotify, 0, (void *)handle_x_button, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, (void *)handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, (void *)draw_simple_scene, &data);
	mlx_loop(data.mlx_ptr);
	free_mlx_data(&data);
	return (0);
}
