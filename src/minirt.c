/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:27:08 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_scn	scene;
	t_prs	parser;

	if (init_mlx_data(&(scene.mlx)) < 0)
		return (1);
	if (argc < 2)
	{
		printf("Return a default scene.\n");
		if (scn_setup(&scene) < 0)
			return (1);
	}
	else if (argc > 2)
	{
		printf("Too many files given in argument\n");
		return (1);
	}
	else
	{
		parser.scn = &scene;
		memset(&scene, 0, sizeof(t_scn));
		parser.fname = argv[1];
		parser.amb_count = 0;
		parser.cam_count = 0;		
		if (prs_rtfile(&parser) == -1)
		{
			scn_dlt(&scene);
			printf("Error Encountered\n");
			return (1);
		}
	}
	scene.itxv = itxv_crt(10);
	if (scene.itxv.v == NULL)
		return (-1);
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
