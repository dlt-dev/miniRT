/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:16:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:07:25 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>
# include <math.h>
# define EPS 1e-9

// Utility Functions
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		display_progressbar(double percent);
void		display_progress(int i, int j);

bool		deql(double a, double b);	// Equality for 2 doubles.

#endif