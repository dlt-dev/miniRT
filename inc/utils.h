/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:16:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/21 11:58:04 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>
# include <math.h>
# define EPS 1e-9
# define PI 3.14159265358979323846

typedef struct s_tuple
{
	double	x;
	double	y;
}	t_tpl;

// Utility Functions
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		display_progressbar(double percent);
void		display_progress(int i, int j);

bool		deql(double a, double b);	// Equality for 2 doubles.

void		tpl_sort(t_tpl *tuple);	// Sorts a tuple so that x <= y.

#endif