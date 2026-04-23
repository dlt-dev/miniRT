/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt_vprd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:33:30 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 15:16:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	m44_fill_mat(const t_m44 *m1, char m_buf[4][4][64], int m_w[4])
{
	int	row;
	int	col;
	int	len;

	col = 0;
	while (col < 4)
	{
		m_w[col] = 0;
		row = 0;
		while (row < 4)
		{
			m44_fmt_value((*m1)[row * 4 + col], m_buf[row][col]);
			len = (int)strlen(m_buf[row][col]);
			if (len > m_w[col])
				m_w[col] = len;
			row++;
		}
		col++;
	}
}

static void	m44_fill_vec(const t_v4 *v, char v_buf[4][64], int *v_w)
{
	double	vals[4];
	int		row;
	int		len;

	vals[0] = v->x;
	vals[1] = v->y;
	vals[2] = v->z;
	vals[3] = v->w;
	*v_w = 0;
	row = 0;
	while (row < 4)
	{
		m44_fmt_value(vals[row], v_buf[row]);
		len = (int)strlen(v_buf[row]);
		if (len > *v_w)
			*v_w = len;
		row++;
	}
}

static void	m44_print_vprd(t_m44_vprd_disp *d)
{
	char	*left[4];
	char	*right[4];
	int		row;

	left[0] = "╭";
	left[1] = "│";
	left[2] = "│";
	left[3] = "╰";
	right[0] = "╮";
	right[1] = "│";
	right[2] = "│";
	right[3] = "╯";
	row = 0;
	while (row < 4)
	{
		m44_print_row_left_vprd(d, row, left[row], right[row]);
		m44_print_row_right_vprd(d, row, left[row], right[row]);
		row++;
	}
}

void	m44_prt_vprd(const t_m44 *m1, const t_v4 *v1, const t_v4 *v2)
{
	t_m44_vprd_disp	d;

	if (!m1 || !v1 || !v2)
		return ;
	m44_fill_mat(m1, d.m_buf, d.m_w);
	m44_fill_vec(v1, d.v1_buf, &d.v_w[0]);
	m44_fill_vec(v2, d.v2_buf, &d.v_w[1]);
	m44_print_vprd(&d);
}
