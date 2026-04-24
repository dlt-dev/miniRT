/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x_buton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:18:21 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/24 11:43:31 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_x_button(t_scn *scene)
{
	mlx_destroy_window(scene->mlx.mlx_ptr, scene->mlx.mlx_win);
	scene->mlx.mlx_win = NULL;
	free_mlx_data(&(scene->mlx));
	scn_dlt(scene);
	exit(0);
	return (0);
}
