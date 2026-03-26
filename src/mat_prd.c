/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_prd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:34:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:08:48 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static int	check_mat(const t_mat *m1, const t_mat *m2, t_mat *res)
{
	if (!m1 || !m2 || !res || !m1->m || !m2->m)
		return (-1);
	if (m1->c != m2->r)
		return (-1);
	if (res->r != m1->r || res->c != m2->c)
	{
		if (res->m)
			mat_dlt(res);
		res->r = m1->r;
		res->c = m2->c;
		if (!mat_crt(res))
			return (-1);
	}
	return (0);
}

int	mat_prd(const t_mat *m1, const t_mat *m2, t_mat *res)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;
	double	sum;

	if (!check_mat(m1, m2, res))
		return (-1);
	i = -1;
	while (++i < res->r)
	{
		j = -1;
		while (++j < res->c)
		{
			sum = 0.0;
			k = -1;
			while (++k < m1->c)
				sum += m1->m[i * m1->c + k] * m2->m[k * m2->c + j];
			res->m[i * res->c + j] = sum;
		}
	}
	return (0);
}
