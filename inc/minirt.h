/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:34:58 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 16:44:40 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "camera.h"
# include "ray.h"
# include "color.h"

# define WIN_H 1080
# define WIN_W 1920
# define WIN_NAME "minirt"

# define BAR_WIDTH 50

# define COLOUR1 0x00f44336

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
	t_camera	cam;
}			t_mlx_data;

// MLX Related Functions
void		close_display(t_mlx_data *data);
int			handle_keypress(int keysym, t_mlx_data *data);
int			handle_x_button(t_mlx_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);
int			init_mlx_data(t_mlx_data *d);
void		free_mlx_data(t_mlx_data *data);

// Utility Functions
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		display_progressbar(double percent);
void		display_progress(int i, int j);

#endif
