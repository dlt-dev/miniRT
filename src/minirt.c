/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:33:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 11:25:15 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"
#include <stdio.h>

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

int	main(void)
{
	t_mlx_data	data;

	if (init_mlx_data(&data) < 0)
		return (1);
	srand(time(NULL));
	mlx_hook(data.mlx_win, DestroyNotify, 0, handle_x_button, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &raytrace, &data);
	mlx_loop(data.mlx_ptr);
	free_mlx_data(&data);
	return (0);
}
