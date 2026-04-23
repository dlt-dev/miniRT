/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 13:48:43 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>


typedef struct	s_simple_scene
{
	t_pt	ro;		// Ray origin.
	double	wall_z;	// Wall's distance along the z axis.
	double	wall_s;	// Wall's size.
	int		cvs_px;	// Canvas pixels count.
	double	px_siz;	// Pixel size.
	double	half;	// Midpoint on the wall.
	t_wld	wld;	// Object we want to draw.
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
	t_itxv	itxv;
	t_clr	clr;

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
	wld_ini_dflt(&(scene.wld));
	scene.wld.objs.v[0].mtrl.amb = 0.1;
	scene.wld.objs.v[0].mtrl.spc = 0.8;
	scene.wld.objs.v[0].mtrl.shi = 0.8;
	scene.wld.objs.v[0].mtrl.clr = clr_unpack(BLUE);
	scene.wld.objs.v[1].mtrl.amb = 0.3;
	scene.wld.objs.v[1].mtrl.clr = clr_unpack(RED);

	scene.wld.lgts.v[0].clr = clr_mul(scene.wld.lgts.v[0].clr, 0.75);

	itxv = itxv_crt(2);
	
	obj_trl(&(scene.wld.objs.v[0]), 1, 0, 2);
	obj_rot(&(scene.wld.objs.v[0]), 3, 4, 6);
	obj_scl(&(scene.wld.objs.v[0]), 0.5, 0.5, 0.5);
	obj_she(&(scene.wld.objs.v[0]), (t_spara){1,0.0,0,0,0,0});
	//obj_trl(&(scene.wld.objs.v[0]), -1, 0, -2);
	obj_trl(&(scene.wld.objs.v[1]), -1, 0, -2);
	obj_rot(&(scene.wld.objs.v[1]), 3, 4, 6);
	obj_scl(&(scene.wld.objs.v[1]), 0.5, 0.5, 0.5);
	obj_she(&(scene.wld.objs.v[1]), (t_spara){1,0.0,0,0,0,0});
	
	obj_trf(&(scene.wld.objs.v[0]));
	obj_trf(&(scene.wld.objs.v[1]));
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
			clr = wld_clr_at(&(scene.wld), &ray, &itxv);
			img_pix_put(&(data->img), x, y, clr_pack(clr));
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
