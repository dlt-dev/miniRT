/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:34:58 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/01 11:47:31 by cybourge         ###   ########.fr       */
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
# include <time.h>
# include "utils.h"
# include "color.h"
# include "interval.h"
# include "vector4.h"

# define WIN_H 1080
# define WIN_W 1920
# define WIN_NAME "minirt"

# define BAR_WIDTH 50

# define COLOUR1 0x00f44336

typedef struct s_tuple
{
	double	x;
	double	y;
}	t_tuple;

// The Direction must be Normalized !
typedef struct s_ray
{
	t_pt	o;
	t_v4	dir;
}	t_ray;

typedef struct s_sphere
{
	t_pt				c;
	double				r;
	t_clr				clr;
}	t_sph;

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
void		close_display(t_mlx_data *data);
int			handle_keypress(int keysym, t_mlx_data *data);
int			handle_x_button(t_mlx_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);
int			init_mlx_data(t_mlx_data *d);
void		free_mlx_data(t_mlx_data *data);

// RAY FUNCTIONS
// returns the point at the given distance t along the ray r.
t_pt ray_pos(const t_ray *ray, double t);

// OBJECT FUNCTIONS
// returns an instance of sphere
t_sph sph_crt(void);
// returns wether a ray hits a sphere and notes the coordinates of the hit
// in hit_res
bool sph_hit(const t_sph *sp, const t_ray *r, t_tuple *hit_res);

#endif
