/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:14:33 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/17 10:31:54 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils.h"
# include "minirt.h"

// Structure used to hold that parameters of the ambient light.

typedef struct s_parser
{
	char	*fname;
	int		fd;
	t_scn	*scn;
	int		cam_count;
	int		amb_count;
}	t_prs;

// Used to simplify syntax when returning function pointers.
typedef int	(*t_parsef)(t_prs *, char **);

// Used to store parsing function and their identifiers.
typedef struct s_parser_fun
{
	char		*id;
	t_parsef	func;
}	t_prs_func;

// Structure Used to hold cylinder related data while parsing.
typedef struct s_cyl_data
{
	t_pt	c;
	t_v4	ax;
	double	rad;
	double	h;
	t_clr	clr;
}	t_cyldata;

// Prints a Parsing structure to stdout.
void	prs_prt(const t_prs *prs);

// Parses the data for an ambient light.
// Returns -1 on errors, 0 otherwise.
int		prs_ambient(t_prs *prs, char **ltab);
// Parses the data for a camera.
// Returns -1 on errors, 0 otherwise.
int		prs_camera(t_prs *prs, char **ltab);
// Parses the data for a point light.
// Returns -1 on errors, 0 otherwise.
int		prs_light(t_prs *prs, char **ltab);
// Parses the data for a sphere.
// Returns -1 on errors, 0 otherwise.
int		prs_sphere(t_prs *prs, char **ltab);
// Parses the data for a plane.
// Returns -1 on errors, 0 otherwise.
int		prs_plane(t_prs *prs, char **ltab);
// TBD : Parses the data for a cylinder.
// Returns -1 on errors, 0 otherwise.
int		prs_cylinder(t_prs *prs, char **ltab);
// TBD : Parses the data for a cone.
// Returns -1 on errors, 0 otherwise.
int		prs_cone(t_prs *prs, char **ltab);

// Parses the lines in a file.
// Returns -1 on errors, 0 otherwise.
int		prs_lines(t_prs *prs);
// Parses a color in string form : "r,g,b" where r,g,b ∈ [0,255]
// writes the results in clr.
// Returns -1 on errors, 0 otherwise.
int		prs_clr(const char *input, t_clr *clr);
// Parses a triplet of numbers in string form : "x,y,z" where x,y,z ∈ ℝ
// writes the result in v.
// Returns -1 on errors, 0 otherwise.
int		prs_v3(char *str, t_v4 *v, bool is_vector);
// Parses an objects material data given in string form :
// "a,b,c,d" where :
// a = ambient light effect.
// b = specular light effect.
// c = diffuse light effect.
// d = shininess of the object.
// writes the results in v.
// Returns -1 on error, 0 otherwise.
int		prs_mat(const char *str, t_mtl *mat);
// Checks if the scene's minimal parameters have been properly set.
// Returns -1 if not, 0 otherwise.
int		prs_cmplt(t_prs *prs);
// Parses a .rt file
// Returns -1 on errors, 0 otherwise.
int		prs_rtfile(t_prs *prs);

#endif