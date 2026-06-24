/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 09:46:46 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/22 10:17:10 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
int	simple_render(t_mlx_data *data)
{
	if (data->mlx_win == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.mlx_img, 0, 0);
	return (0);
}

int main(void)
{
	t_ftex		ftex;
	t_mlx_data	data;

	if (init_mlx_data(&data) < 0)
	{
		printf("error 1\n");
		return (1);
	}
	if (ftex_load(&ftex, "earth.xpm", &data) == -1)
	{
		printf("error 2\n");
		return (1);
	}
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	data.img = ftex.img;
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask,
		(void *)handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, (void *)simple_render, &data);
	mlx_loop(data.mlx_ptr);
	// ftex_dlt(&ftex, &data); // Already getting cleaned in free_mlx_data given we copy into it above.
	free_mlx_data(&data);
	return (0);
}
*/