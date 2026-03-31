/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_inv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:25:38 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 10:31:24 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	swap_rows(double a[4][8], int r1, int r2)
{
	int		j;
	double	tmp;

	j = 0;
	while (j < 8)
	{
		tmp = a[r1][j];
		a[r1][j] = a[r2][j];
		a[r2][j] = tmp;
		j++;
	}
}

int	m44_inv(const t_m44 *m1, t_m44 *res)
{
	double	a[4][8];
	int		i;
	int		j;
	int		k;
	double	pivot;
	double	factor;

	if (!m1 || !res)
		return (-1);
	i = 0;
	while (i < M44_SIZE)
	{
		j = 0;
		while (j < M44_SIZE)
		{
			a[i][j] = (*m1)[i * M44_SIZE + j];
			a[i][j + 4] = (i == j);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < M44_SIZE)
	{
		if (a[i][i] == 0.0)
		{
			k = i + 1;
			while (k < M44_SIZE && a[k][i] == 0.0)
				k++;
			if (k == M44_SIZE)
				return (-1);
			swap_rows(a, i, k);
		}
		pivot = a[i][i];
		j = 0;
		while (j < 8)
		{
			a[i][j] /= pivot;
			j++;
		}
		k = 0;
		while (k < M44_SIZE)
		{
			if (k != i)
			{
				factor = a[k][i];
				j = 0;
				while (j < 8)
				{
					a[k][j] -= factor * a[i][j];
					j++;
				}
			}
			k++;
		}
		i++;
	}
	i = 0;
	while (i < M44_SIZE)
	{
		j = 0;
		while (j < M44_SIZE)
		{
			(*res)[i * M44_SIZE + j] = a[i][j + 4];
			j++;
		}
		i++;
	}
	return (0);
}
