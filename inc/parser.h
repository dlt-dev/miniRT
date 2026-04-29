/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:14:33 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:42:02 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils.h"
# include "minirt.h"

// Structure used to hold that parameters of the ambient light.
typedef struct s_ambient_light
{
	double	intensity;
	t_clr	clr;
}	t_ambl;

typedef struct s_parser
{
	char	*fname;
	int		fd;
	t_scn	*scn;
	t_ambl	ambl;
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

// Prints a Parsing structure to stdout.
void	prs_prt(const t_prs *prs);

// Parsing Functions:
int	prs_ambient(t_prs *prs, char **ltab);
int	prs_camera(t_prs *prs, char **ltab);
int	prs_light(t_prs *prs, char **ltab);
int	prs_sphere(t_prs *prs, char **ltab);
int	prs_plane(t_prs *prs, char **ltab);
int	prs_cylinder(t_prs *prs, char **ltab);

// Parses the lines in a file.
// Returns -1 on errors, 0 otherwise.
int	prs_lines(t_prs *prs);

// Parses a color given by input and writes the results in clr.
int	prs_clr(const char *input, t_clr *clr);
// Parses a triplet of numbers stored in str.
int	prs_v3(char *str, t_v4 *v, bool is_vector);
// Checks if the scenes minimal parameters have been properly set.
// Returns -1 if not, 0 otherwise.
int	prs_cmplt(t_prs *prs);
// TBD
int	prs_patch(t_prs *prs);
// Parses a .rt file
// Returns -1 on errors, 0 otherwise.
int	prs_rtfile(t_prs *prs);

#endif