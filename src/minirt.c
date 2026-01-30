/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/01/30 17:01:13 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

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

int	main(void)
{
	t_mlx_data	data;

	if (init_mlx_data(&data) < 0)
		return (1);
	mlx_hook(data.mlx_win, DestroyNotify, 0, handle_x_button, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &raytrace, &data);
	mlx_loop(data.mlx_ptr);
	free_mlx_data(&data);
	return (0);
}
