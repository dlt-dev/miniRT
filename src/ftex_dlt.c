/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_dlt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 09:48:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/22 09:54:39 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

int	ftex_dlt(t_ftex *ftex, t_mlx_data *data)
{
	if (!data || !data->mlx_ptr)
		return (1);
	if (ftex->img.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, ftex->img.mlx_img);
	return (0);
	ft_memset(ftex, 0, sizeof(t_ftex));
	return (0);
}
