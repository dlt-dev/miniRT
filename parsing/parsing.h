/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:03:19 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/27 12:19:11 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR -1

typedef enum e_obj_type
{
	DEFAULT, // 0
	SPHERE,  // 1
	PLANE,   // 2
	CYLINDER // 3
}					t_obj_type;

typedef struct s_vect3 ////
{
	double x;
	double y;
	double z;
}					t_vect3;

typedef t_vect3		t_point;

typedef struct color ////
{
	double r;
	double g;
	double b;
	double t;
}					t_color;

typedef struct s_sphere
{
	t_point			center;
	double			radius;
	t_color			color;

}					t_sphere;

typedef struct s_plane
{
	t_point			center;
	t_vect3			normal;
	t_color			color;

}					t_plane;

typedef struct s_cylinder
{
	t_point			center;
	t_vect3			axis; // normalisee
	double			diameter;
	double			height;
	t_color			color;

}					t_cylinder;

typedef struct s_ambient
{
	float			ratio;
	t_color			color;
	int				count;
}					t_ambient;

typedef struct s_camera
{
	t_point			camera_loc;
	t_vect3 orientation_vect; //[-1,1]
	int fov;                  // 0,180]
	int				count;
}					t_camera;

typedef struct s_light
{
	t_point			light_loc;
	float			ratio;
	t_color			color;
	int				count;
}					t_light;

/* typedef union u_object
{
	t_sphere		sp;
	t_plane			pl;
	t_cylinder		cy;

}				t_object; */

typedef struct s_object
{
	int				type;

	union
	{
		t_sphere	sp;
		t_plane		pl;
		t_cylinder	cy;
	} u;

}					t_object;

typedef struct s_obj_lst
{
	int				obj_type;

	union
	{
		t_sphere	sp;
		t_plane		pl;
		t_cylinder	cy;
	} u;

	struct s_obj_lst *next; // pour stocker les obj avant l'alloc du tableau

}					t_obj_lst;

typedef struct s_rt_data
{
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_obj_lst		*obj_list;
	t_object		*obj_tab;
	int				obj_count;

}					t_rt_data;

// split.c
char				**ft_split(char const *s, char c);

// get_next_line.c
char				*get_next_line(int fd);

// get_next_line_utils.c
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *str, int c);
void				*ft_memcpy(void *dest, const void *source, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

// check_value.c
int					check_color(t_color c);
int					check_vect(t_vect3 v);
int					is_valid_number(const char *str);
int					is_valid_positive_int(const char *str);

// pars_value.c
int					pars_color(char *str, t_color *c);
int					pars_vect3(char *str, t_vect3 *v);

// free.c
void				ft_free_lst(t_obj_lst **lst);
void				free_all(t_rt_data *data);
int					print_err_free(char *message, t_rt_data *data);
void				free_tab(char **tab);

// libft_utils.c
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *s);
void				ft_bzero(void *s, size_t n);
double				ft_atof(const char *str);
int					tab_len(char **tab);

// print_test
void				print_vect3(t_vect3 v);       // test
void				print_color(t_color c);       // test
void				print_datatest(t_rt_data *d); // test

// param.c
int					pars_ambient(char **tab, t_rt_data *data);
int					pars_camera(char **tab, t_rt_data *data);
int					pars_light(char **tab, t_rt_data *data);

// object.c
int					pars_sphere(char **tab, t_rt_data *data);
int					pars_plane(char **tab, t_rt_data *data);
int					pars_cylinder(char **tab, t_rt_data *data);

// utils_obj_list
t_obj_lst			*ft_lstnew_obj(int type);
t_obj_lst			*ft_lstlast(t_obj_lst *lst);
void				ft_lstadd_back(t_obj_lst **lst, t_obj_lst *new);
int					ft_lstsize(t_obj_lst *lst);

// init.c
void				init_rt_data(t_rt_data *data);
int					init_obj_tab(t_rt_data *data);

// parsing.c
int					check_file(char *file);
int					pars_line(char *line, t_rt_data *data);
int	main(int ac, char **av); // parsing_rt()

#endif
