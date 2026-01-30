/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:11:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/01/30 10:51:43 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// returns -1 on error 0 on success
int	init_mlx_data(t_mlx_data *d)
{
	t_img	*i;

	ft_memset(d, 0, sizeof(d));
	i = &(d->img);
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return (-1);
	d->mlx_win = mlx_new_window(d->mlx_ptr, WIN_W, WIN_H, WIN_NAME);
	if (d->mlx_win == NULL)
		return (free_mlx_data(d), -1);
	i->mlx_img = mlx_new_image(d->mlx_ptr, WIN_W, WIN_H);
	if (i->mlx_img == NULL)
		return (free_mlx_data(d), -1);
	i->addr = mlx_get_data_addr(i->mlx_img, &(i->bpp), &(i->ll), &(i->endian));
	return (0);
}
