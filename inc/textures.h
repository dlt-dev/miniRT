/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 08:56:07 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/22 10:47:50 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "mlx_utils.h"
# include "utils.h"
# include "color.h"
# include "vector4.h"

typedef enum e_texture_types
{
	BASE_TEX = 0,
	PATTERN_TEX,
	FILE_TEX,
}	t_textype;

typedef struct s_texture
{
	t_textype type;
	union
	{
		//t_pat	ptex;
		//t_ftex	ftex;
	}	u_tex;
}	t_tex;

// Structure that holds the data required to use textures loaded from files.
// Current supported file formats : .XPM
typedef struct s_file_texture
{
	t_img	img;
	int		h;
	int		w;
}	t_ftex;

// Loads the file at fpath into the ftex structure.
// Returns -1 on Errors, 0 otherwise.
// Currently only loads .xpm files.
int	ftex_load(t_ftex *ftex, char *fpath, t_mlx_data *data);

// Deletes the ftex.
// Returns -1 on Errors, 0 otherwise.
int	ftex_dlt(t_ftex *ftex, t_mlx_data *data);

// Returns the color of the pixel on the object relative to the texture.
t_clr	ftex_clr(const t_ftex *ftex, const t_pt *point);

#endif