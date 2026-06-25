/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 09:00:38 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:28:46 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <stdbool.h>
# include "mlx.h"
# include <stddef.h>

typedef struct s_scene	t_scn;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}			t_img;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	bool		update;
}			t_mlx_data;

// MLX FUNCTIONS
void	close_display(t_mlx_data *data);
int		handle_keypress(int keysym, t_mlx_data *data);
int		handle_x_button(t_scn *scene);
void	img_pix_put(t_img *img, int x, int y, int color);
int		init_mlx_data(t_mlx_data *d);
void	free_mlx_data(t_mlx_data *data);

#endif