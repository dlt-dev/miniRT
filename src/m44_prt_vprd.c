/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt_vprd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:33:30 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/17 17:49:50 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

// void	m44_prt_vprd(const t_m44 *m1, const t_v4 *v1, const t_v4 *v2)
// {
// 	if (!m1 || !v1 || !v2)
// 		return ;
// 	printf(
// 		"╭%8.3f %8.3f %8.3f %8.3f╮   ╭ %8.3f ╮   ╭ %8.3f ╮\n"
// 		"│%8.3f %8.3f %8.3f %8.3f│ * │ %8.3f │ = │ %8.3f │\n"
// 		"│%8.3f %8.3f %8.3f %8.3f│   │ %8.3f │   │ %8.3f │\n"
// 		"╰%8.3f %8.3f %8.3f %8.3f╯   ╰ %8.3f ╯   ╰ %8.3f ╯\n",
// 		(*m1)[0], (*m1)[1], (*m1)[2], (*m1)[3],
// 		v1->x, v2->x,
// 		(*m1)[4], (*m1)[5], (*m1)[6], (*m1)[7],
// 		v1->y, v2->y,
// 		(*m1)[8], (*m1)[9], (*m1)[10], (*m1)[11],
// 		v1->z, v2->z,
// 		(*m1)[12], (*m1)[13], (*m1)[14], (*m1)[15],
// 		v1->w, v2->w
// 		);
// }

static void	m44_fmt_value(double value, char out[64])
{
	int	end;

	if (value == 0.0)
	{
		out[0] = '0';
		out[1] = '\0';
		return ;
	}
	snprintf(out, 64, " %.17g", value);
	end = (int)strlen(out) - 1;
	while (end > 0 && out[end] == '0')
	{
		out[end] = '\0';
		end--;
	}
	if (end > 0 && out[end] == '.')
		out[end] = '\0';
}

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

static void	m44_print_vprd(char m_buf[4][4][64], int m_w[4],
		char v1_buf[4][64], char v2_buf[4][64], int v_w[2])
{
	char	*left[4];
	char	*right[4];
	int		row;
	int		col;

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
		printf("%s", left[row]);
		col = 0;
		while (col < 4)
		{
			printf(" %*s", m_w[col], m_buf[row][col]);
			col++;
		}
		printf(" %s", right[row]);
		if (row == 1)
			printf(" * ");
		else
			printf("   ");
		printf("%s %*s %s", left[row], v_w[0], v1_buf[row], right[row]);
		if (row == 1)
			printf(" = ");
		else
			printf("   ");
		printf("%s %*s %s\n", left[row], v_w[1], v2_buf[row], right[row]);
		row++;
	}
}

void	m44_prt_vprd(const t_m44 *m1, const t_v4 *v1, const t_v4 *v2)
{
	char	m_buf[4][4][64];
	char	v1_buf[4][64];
	char	v2_buf[4][64];
	int		m_w[4];
	int		v_w[2];

	if (!m1 || !v1 || !v2)
		return ;
	m44_fill_mat(m1, m_buf, m_w);
	m44_fill_vec(v1, v1_buf, &v_w[0]);
	m44_fill_vec(v2, v2_buf, &v_w[1]);
	m44_print_vprd(m_buf, m_w, v1_buf, v2_buf, v_w);
}
