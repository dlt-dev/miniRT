/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 09:34:03 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/24 18:12:24 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

int	ftex_load(t_ftex *ftex, char *fpath, t_mlx_data *data)
{
	memset(ftex, 0, sizeof(t_ftex));
	ftex->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, fpath, &(ftex->w), &(ftex->h));
	if (ftex->img.mlx_img == NULL)
		return (-1);
	ftex->img.addr = mlx_get_data_addr(ftex->img.mlx_img, &(ftex->img.bpp), &(ftex->img.ll), &(ftex->img.endian));
	if (ftex->img.addr == NULL)
		return (mlx_destroy_image(data->mlx_ptr, ftex->img.mlx_img), -1);
	return (0);
}
