/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/28 12:08:06 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <stdio.h>

static int	parse_scene(t_scn *scene, char **argv)
{
	t_prs	parser;

	parser.scn = scene;
	parser.fname = argv[1];
	parser.amb_count = 0;
	parser.cam_count = 0;
	if (prs_rtfile(&parser) == -1)
		return (-1);
	return (0);
}

static int	setup_scene(t_scn *scene, char **argv, int argc)
{
	ft_memset(scene, 0, sizeof(t_scn));
	if (init_mlx_data(&(scene->mlx)) < 0)
		return (-1);
	if (argc < 2)
	{
		printf("Rendering the default scene.\n");
		if (scn_setup(scene) < 0)
			return (free_mlx_data(&(scene->mlx)), -1);
	}
	else if (argc > 2)
	{
		printf("Too many files given in argument\n");
		return (free_mlx_data(&(scene->mlx)), -1);
	}
	else if (parse_scene(scene, argv) == -1)
		return (scn_dlt(scene), free_mlx_data(&(scene->mlx)), -1);
	scene->itxv = itxv_crt(10);
	if (scene->itxv.v == NULL)
		return (scn_dlt(scene), free_mlx_data(&(scene->mlx)), -1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scn	scene;

	if (setup_scene(&scene, argv, argc) == -1)
		return (printf("Error Encountered\n"), 1);
	mlx_hook(scene.mlx.mlx_win, DestroyNotify, StructureNotifyMask,
		(void *)handle_x_button, &(scene));
	mlx_hook(scene.mlx.mlx_win, KeyPress, KeyPressMask,
		(void *)handle_keypress, &(scene.mlx));
	mlx_loop_hook(scene.mlx.mlx_ptr, (void *)scn_render, &scene);
	mlx_loop(scene.mlx.mlx_ptr);
	scn_dlt(&scene);
	free_mlx_data(&(scene.mlx));
	return (0);
}
