/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:34:58 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 10:59:40 by cybourge         ###   ########.fr       */
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
# include "camera.h"

# define WIN_H 1080
# define WIN_W 1920
# define WIN_NAME "minirt"

# define BAR_WIDTH 50

# define COLOUR1 0x00f44336

# define NB_OBJ	5

typedef struct color
{
	double	r;
	double	g;
	double	b;
	double	t;
}			t_color;

typedef struct s_tuple
{
	double	x;
	double	y;
}	t_tuple;

typedef struct s_itv
{
	double	min;
	double	max;
}	t_itv;

typedef struct s_ray
{
	t_point	o;
	t_vect3	dir;	// Normalized
}	t_ray;

typedef struct s_hitinfo
{
	t_point		p;	// point of contact.
	t_vect3		n;	// normal vector to the surface
	double		t;	// ray parameter
	bool		front_face; // does the ray hit inside or outside the geometry
}				t_hitinfo;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}			t_img;

typedef struct s_sphere
{
	t_point				c;
	double				r;
	t_color				color;
	// bool	(*is_hit)(t_sphere *, t_ray *, t_hitinfo *);
}						t_sphere;

typedef struct s_plane
{
	t_point	p;
	t_vect3	nnv;
	t_color	color;
}	t_pln;

typedef struct s_cone
{
	t_point	bc;		// base centerpoint
	t_point	tip;	// cone tip
	double	r;		// radius
	t_color	color;
}	t_cone;

typedef struct t_triangle
{
	t_point	a;
	t_point	b;
	t_point	c;
	t_color	color;
}	t_trgl;

typedef struct s_cylinder
{
	t_point	c;
	t_vect3	axis;		// Normalized
	double	r;
	double	h;
	t_color	color;
	t_point	capt; // center point on the top circle cap
	t_point	capb; // center point on the bottom circle cap
}	t_cldr;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	bool		update;
	t_camera	cam;
	t_sphere	sphere[NB_OBJ];
	t_pln		plane;
	t_cldr		cylinder;
	t_cone		cone;
	t_trgl		triangle;
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
int 		quadratic_roots(double a, double b, double c, t_tuple *roots);
bool		ray_pln_intersection(const t_ray *ray, const t_pln *plane, double *t);
bool		rd_int(const t_ray *ray, const t_vect3 *disc_o, const t_vect3 *disc_n, double radius, double *t);


double		random_double(double min, double max);

// Color Functions
uint32_t	trgb_pack(const t_color *c);
t_color		trgb_unpack(uint32_t packed);

// Object Related Functions
bool		itv_contains(const t_itv *interval, double value);
bool		itv_surrounds(const t_itv *interval, double value);
double		itv_clamp(t_itv *interval, double value);

void	hitinfo_set_face_normal(t_hitinfo *hitinfo, const t_ray *ray, const t_vect3 *outward_normal);

double		sphere_is_hit(t_sphere *sphere, t_ray *ray);
bool		sphere_is_hit_test(t_sphere *sphere, t_ray *ray);
bool		sphere_hit(t_sphere *sphere, t_ray *ray, t_hitinfo *info, t_itv *iterval);
bool		pln_hit(t_pln *plane, t_ray *ray, t_hitinfo *info, t_itv *interval);
bool		cldr_hit(t_cldr *cylinder, t_ray *ray, t_hitinfo *info, t_itv *interval);
bool		cone_hit(t_cone *cone, t_ray *ray, t_hitinfo *info, t_itv *interval);
bool		trgl_hit(t_trgl *triangle, t_ray *ray, t_hitinfo *info, t_itv *interval);

// Ray Functions
t_vect3	ray_at(t_ray ray, double t);
t_color	ray_color(t_ray ray, t_mlx_data *d);

#endif
