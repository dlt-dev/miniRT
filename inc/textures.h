/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 08:56:07 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:19:44 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "mlx_utils.h"
# include "utils.h"
# include "color.h"
# include "vector4.h"
# include "matrix.h"
# include "transformations.h"

struct	s_texture;

typedef enum e_texture_types
{
	BASE_TEX = 0,
	PATTERN_TEX,
	FILE_TEX,
}	t_textype;

// Structure that holds the data required to use textures loaded from files.
// Current supported file formats : .XPM
typedef struct s_file_texture
{
	t_img	img;
	int		h;
	int		w;
}	t_ftex;

typedef struct s_pattern
{
	t_clr	(*pat)(const struct s_texture *, const t_pt *);
	t_clr	clr1;
	t_clr	clr2;
}	t_pat;

typedef struct s_texture
{
	t_textype	type;
	union
	{
		t_pat	ptex;
		t_ftex	ftex;
	}	u_tex;
}	t_tex;

typedef struct s_texture_vector
{
	size_t	len;
	size_t	cap;
	t_tex	*v;
}	t_texv;

// Creates an empty texture vector with a capacity of cap.
// If the allocation is unsucessfull:
//	- cap = 0.
//	- v = NULL.
t_texv	texv_crt(size_t cap);

// Frees the texture vector and sets all its field to 0.
void	texv_dlt(t_texv *texv, t_mlx_data *data);

// Adds a file texture to the texture vector.
// Reallocates twice the capacity if needed.
// Returns -1 on errors, 0 otherwise.
int		texv_add_ftex(t_texv *texv, char *fpath, t_mlx_data *data);

// Adds a pattern texture to the texture vector.
// Reallocates twice the capacity if needed.
// Returns -1 on errors, 0 otherwise.
int		texv_add_pat(t_texv *texv, const t_pat *pat);

// Loads the file at fpath into the ftex structure.
// Returns -1 on Errors, 0 otherwise.
// Currently only loads .xpm files.
int		ftex_load(t_ftex *ftex, char *fpath, t_mlx_data *data);

// Deletes the ftex.
// Returns -1 on Errors, 0 otherwise.
int		ftex_dlt(t_ftex *ftex, t_mlx_data *data);

// Returns the color of the pixel on the object relative to the texture.
t_clr	ftex_clr(const t_ftex *ftex, const t_pt *point);

// returns the color of a vertical stripped pattern at point p
t_clr	pat_strp1(const t_tex *tex, t_pt const *p);

// returns the color of a gradient pattern.
t_clr	pat_lgrad1(const t_tex *tex, t_pt const *p);

// returns the color of a ring pattern.
t_clr	pat_ring1(const t_tex *tex, t_pt const *p);

// returns the color of a Square Checker pattern.
t_clr	pat_chkr1(const t_tex *tex, t_pt const *p);

// returns the color of a Rectangular Checker pattern.
t_clr	pat_chkr2(const t_tex *tex, t_pt const *p);

#endif