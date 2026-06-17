/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:16:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/17 11:14:32 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>
# include <math.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "interval.h"
# define EPS 				1e-9
# define PI 				3.14159265358979323846
# define GNL_BUFFER_SIZE	256
# define GNL_CLEAR			-2

typedef struct s_tuple
{
	double	x;
	double	y;
}	t_tpl;

// Utility Functions
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_atoi(const char *s);
double		ft_atof(const char *str);
void		ft_bzero(void *s, size_t n);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char *sep);
void		display_progressbar(double percent);
void		display_progress(int i, int j);

char		*gnl(int fd);

int			tab_len(char **tab);
void		tab_dlt(char **tab);

bool		deql(double a, double b);	// Equality for 2 doubles.

void		tpl_sort(t_tpl *tuple);	// Sorts a tuple so that x <= y.

// Returns wether the argument is a string that represents a valid float.
bool		is_validf(const char *str);
// Returns True is the string is a valid unsigned int.
bool		is_validui(const char *str);
// Returns true if the fields of the array properly define a color.
bool		is_validclr(char **tab);

//Prints an error message on stderr, returns ret.
int			ft_err_prt(const char *msg, int ret);

#endif