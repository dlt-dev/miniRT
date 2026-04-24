/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:34:58 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/24 11:00:36 by cybourge         ###   ########.fr       */
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
# include "ray.h"
# include "object.h"
# include "world.h"
# include "camera.h"

# define WIN_H 144
# define WIN_W 256
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
}			t_mlx_data;

typedef struct s_scene
{
	t_mlx_data	mlx;
	t_wld		world;
	t_cam		camera;
	t_itxv		itxv;
}	t_scn;

// Structure that holds variables used in rendering a scene : 42 norm
typedef struct s_render_utils
{
	size_t	x;
	size_t	y;
	t_ray	ray;
	t_clr	clr;
}	t_rdr_utils;

// MLX FUNCTIONS
void	close_display(t_mlx_data *data);
int		handle_keypress(int keysym, t_mlx_data *data);
int		handle_x_button(t_scn *scene);
void	img_pix_put(t_img *img, int x, int y, int color);
int		init_mlx_data(t_mlx_data *d);
void	free_mlx_data(t_mlx_data *data);

// Renders the scene's world as seen through the scene's camera
// using the scene's mlx parameters.
// Returns -1 on error, 0 otherwise.
int		scn_render(t_scn *scene);

// Utility function to setup the objects in the world
// Returns -1 on error, 0 otherwise.
int		scn_dflt_objs(t_wld *world);

// Utility function to setup the lights in the world.
// Returns -1 on error, 0 otherwise.
int		scn_dflt_lgts(t_wld *world);

// Utility function to setup the camera.
// Returns -1 on error, 0 otherwise.
int		scn_dflt_cam(t_cam *camera);

// Utility function to setup the whole scene.
// Returns -1 on error, 0 otherwise.
int		scn_setup(t_scn *scene);

// Deletes the allocated memory in a acene.
void	scn_dlt(t_scn *scene);

#endif
