/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/24 10:43:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int	main(void)
{
	t_scn	scene;

	if (init_mlx_data(&(scene.mlx)) < 0)
		return (1);
	if (scn_setup(&scene) < 0)
		return (1);
	mlx_hook(scene.mlx.mlx_win, DestroyNotify, 0,
		(void *)handle_x_button, &(scene.mlx));
	mlx_hook(scene.mlx.mlx_win, KeyPress, KeyPressMask,
		(void *)handle_keypress, &(scene.mlx));
	mlx_loop_hook(scene.mlx.mlx_ptr, (void *)scn_render, &scene);
	mlx_loop(scene.mlx.mlx_ptr);
	free_mlx_data(&(scene.mlx));
	return (0);
}
