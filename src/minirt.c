/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/24 09:30:03 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int	render(t_mlx_data *data, const t_cam *cam, const t_wld *world)
{
	size_t	x;
	size_t	y;
	t_ray	ray;
	t_clr	clr;
	t_itxv	itxv;

	if (data->mlx_win == NULL)
		return (-1);
	if (data->update == false)
		return (-1);
	itxv = itxv_crt(4);
	if (itxv.cap == 0)
		return (-1);
	y = 0;
	while (y < cam->vsz)
	{
		x = 0;
		while (x < cam->hsz)
		{
			ray = cam_gen_ray(cam, x, y);
			clr = wld_clr_at(world, &ray, &itxv);
			img_pix_put(&(data->img), x, y, clr_pack(clr));
			x++;
		}
		display_progress(x, y);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.mlx_img, 0, 0);
	data->update = false;
	itxv_dlt(&itxv);
	return (0);
}

void	setup_scene(t_wld *world, t_cam *cam)
{
	// Setup the World.
	world->objs = objv_crt(6);
	if (world->objs.cap == 0)
		printf("Error\n");
	world->lgts = lgtv_crt(1);
	if (world->lgts.cap == 0)
		printf("Error\n");
	world->objs.len = 6;
	world->lgts.len = 1;
	// Sphere 1 setup : The Floor
	world->objs.v[0] = sph_crt();
	obj_scl(&(world->objs.v[0]), 10, 0.01, 10);
	obj_trf(&(world->objs.v[0]));
	world->objs.v[0].mtrl.clr = clr_crt(0.0, 1.0, 0.9, 0.9);
	world->objs.v[0].mtrl.spc = 0;
	// Sphere 2 Setup : Left Wall
	world->objs.v[1] = sph_crt();
	obj_scl(&(world->objs.v[1]), 10, 0.01, 10);
	obj_rot(&(world->objs.v[1]), PI / 2.0, -PI / 4.0, 0.0);
	obj_trl(&(world->objs.v[1]), 0, 0, 5);
	obj_trf(&(world->objs.v[1]));
	world->objs.v[1].mtrl.clr = clr_crt(0.0, 1.0, 0.9, 0.9);
	world->objs.v[1].mtrl.spc = 0;
	// Sphere 3 Setup : Right Wall
	world->objs.v[2] = sph_crt();
	obj_scl(&(world->objs.v[2]), 10, 0.01, 10);
	obj_rot(&(world->objs.v[2]), PI / 2.0, PI / 4.0, 0.0);
	obj_trl(&(world->objs.v[2]), 0, 0, 5);
	obj_trf(&(world->objs.v[2]));
	world->objs.v[2].mtrl.clr = clr_crt(0.0, 1.0, 0.9, 0.9);
	world->objs.v[2].mtrl.spc = 0;
	// Sphere 4 Setup : Middle Sphere
	world->objs.v[3] = sph_crt();
	obj_trl(&(world->objs.v[3]), -0.5, 1.0, 0.5);
	obj_trf(&(world->objs.v[3]));
	world->objs.v[3].mtrl.clr = clr_crt(0.0, 0.1, 1.0, 0.5);
	world->objs.v[3].mtrl.dif = 0.7;
	world->objs.v[3].mtrl.spc = 0.3;
	// Sphere 5 Setup : Right Sphere
	world->objs.v[4] = sph_crt();
	obj_scl(&(world->objs.v[4]), 0.5, 0.5, 0.5);
	obj_trl(&(world->objs.v[4]), 1.5, 0.5, -0.5);
	obj_trf(&(world->objs.v[4]));
	world->objs.v[4].mtrl.clr = clr_crt(0.0, 0.5, 1.0, 0.1);
	world->objs.v[4].mtrl.dif = 0.7;
	world->objs.v[4].mtrl.spc = 0.3;
	// Sphere 6 Setup : Left Sphere
	world->objs.v[5] = sph_crt();
	obj_trl(&(world->objs.v[5]), -1.5, 0.33, -0.75);
	obj_scl(&(world->objs.v[5]), 0.33, 0.33, 0.33);
	obj_trf(&(world->objs.v[5]));
	world->objs.v[5].mtrl.clr = clr_crt(0.0, 1.0, 0.8, 0.1);
	world->objs.v[5].mtrl.dif = 0.7;
	world->objs.v[5].mtrl.spc = 0.3;
	// Light Source Setup
	lgt_set(&(world->lgts.v[0]), pt_crt(-10, 10, -10), WHITE);
	// Setup the Camera.
	cam_ini(cam, WIN_W, WIN_H, PI / 3.0);
	t_pt	from = pt_crt(0, 1.5, -5);
	t_pt	to = pt_crt(0, 1.0, 0);
	t_v4	up = v4_crt(0, 1, 0);
	m44_vtrf(&from, &to, &up, &(cam->vtf));
	m44_inv(&(cam->vtf), &(cam->ivtf));
}

// Temporary structure to hold wrapper's arguments
typedef struct s_temp
{
	t_mlx_data	*data;
	t_wld		*world;
	t_cam		*camera;
}	t_tmp;

int	wrapper(t_tmp *tmp)
{
	return (render(tmp->data, tmp->camera, tmp->world));
}

int	main(void)
{
	t_mlx_data	data;
	t_wld		world;
	t_cam		camera;
	t_tmp		tmp;

	if (init_mlx_data(&data) < 0)
		return (1);
	srand(time(NULL));
	setup_scene(&world, &camera);
	tmp.data = &data;
	tmp.camera = &camera;
	tmp.world = &world;
	mlx_hook(data.mlx_win, DestroyNotify, 0, (void *)handle_x_button, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, (void *)handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, (void *)wrapper, &tmp);
	mlx_loop(data.mlx_ptr);
	free_mlx_data(&data);
	return (0);
}
