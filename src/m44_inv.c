/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_inv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:25:38 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 13:49:05 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static int	find_pivot_row(t_m44 const *a, int i)
{
	int	k;
	int	max_row;

	max_row = i;
	k = i + 1;
	while (k < M44_SIZE)
	{
		if (fabs((*a)[k * M44_SIZE + i]) > fabs((*a)[max_row * M44_SIZE + i]))
			max_row = k;
		k++;
	}
	return (max_row);
}

static void	swap_row(t_m44 *a, int i, int j)
{
	int		k;
	double	tmp;

	k = 0;
	if (i != j)
	{
		while (k < M44_SIZE)
		{
			tmp = (*a)[i * M44_SIZE + k];
			(*a)[i * M44_SIZE + k] = (*a)[j * M44_SIZE + k];
			(*a)[j * M44_SIZE + k] = tmp;
			k++;
		}
	}
}

static void	normalize_pivot_rows(t_m44 *a, t_m44 *b, int i)
{
	int		j;
	double	tmp;

	tmp = (*a)[i * M44_SIZE + i];
	j = 0;
	while (j < M44_SIZE)
	{
		(*a)[i * M44_SIZE + j] /= tmp;
		(*b)[i * M44_SIZE + j] /= tmp;
		j++;
	}
}

static void	eliminate_other_rows(t_m44 *a, t_m44 *b, int i)
{
	double	tmp;
	int		k;
	int		j;

	k = 0;
	while (k < M44_SIZE)
	{
		if (k == i)
			continue ;
		tmp = (*a)[k * M44_SIZE + i];
		j = 0;
		while (j < M44_SIZE)
		{
			(*a)[k * M44_SIZE + j] -= tmp * (*a)[i * M44_SIZE + j];
			(*b)[k * M44_SIZE + j] -= tmp * (*b)[i * M44_SIZE + j];
			j++;
		}
		k++;
	}
}

// Gauss-Jordan Inverse Algorithm
// m1 : Matrix to inverse.
// res : Matrix sotring the inverse of m1 if it exists.
//  - Initialize res as identity matrix.
//  - Make a copy of m1 into a to perform the operations.
//  - Gauss-Jordan Elimination:
//		+ For Every row in a:
//			_ Find Pivot row
//			_ If Matrix a is singular
//				. Return Error
//			_ Swap rows in a and res
//			_ Normalize pivot row
//			_ Eliminate other rows
//	- Return Success

int	m44_inv(const t_m44 *m1, t_m44 *res)
{
	int		i;
	int		max_row;
	t_m44	a;

	if (m44_idm(res) != 0)
		return (-1);
	if (m44_cpy(m1, &a) != 0)
		return (-1);
	i = 0;
	while (i < M44_SIZE)
	{
		max_row = find_pivot_row(&a, i);
		if (deql(a[max_row * M44_SIZE + i], 0.0))
			return (-1);
		swap_row(&a, i, max_row);
		swap_row(res, i, max_row);
		normalize_pivot_rows(&a, res, i);
		eliminate_other_rows(&a, res, i);
		i++;
	}
	return (0);
}
