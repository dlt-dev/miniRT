/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:34:58 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 14:01:07 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "mlx_utils.h"
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
# include "textures.h"


# define WIN_H		1080 //800 // 144
# define WIN_W  	1920 //800  // 256
# define WIN_NAME 	"miniRT"

# define BAR_WIDTH 50


typedef struct s_scene
{
	t_mlx_data	mlx;
	t_wld		world;
	t_cam		camera;
	t_itxv		itxv;
	t_texv		texv;
	t_texv		hmapv;
}	t_scn;

// Structure that holds variables used in rendering a scene : 42 norm
typedef struct s_render_utils
{
	size_t	x;
	size_t	y;
	t_ray	ray;
	t_clr	clr;
}	t_rdr_utils;

// Renders the scene's world as seen through the scene's camera
// using the scene's mlx parameters.
// Returns -1 on error, 0 otherwise.
int		scn_render(t_scn *scene);

// Utility function to setup the objects in the world
// Returns -1 on error, 0 otherwise.
int		scn_dflt_objs(t_wld *world, t_scn *scene);

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
