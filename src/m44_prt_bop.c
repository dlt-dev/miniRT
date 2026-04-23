/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt_bop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:38:27 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 12:16:20 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	m44_fill_mat(const t_m44 *m, char buf[4][4][64], int col_w[4])
{
	int	row;
	int	col;
	int	len;

	col = 0;
	while (col < 4)
	{
		col_w[col] = 0;
		row = 0;
		while (row < 4)
		{
			m44_fmt_value((*m)[row * 4 + col], buf[row][col]);
			len = (int)strlen(buf[row][col]);
			if (len > col_w[col])
				col_w[col] = len;
			row++;
		}
		col++;
	}
}

static void	m44_print_mat_row(t_m44_mat_disp *m, int row,
		const char *left, const char *right)
{
	int		col;

	printf("%s", left);
	col = 0;
	while (col < 4)
	{
		printf(" %*s", m->w[col], m->b[row][col]);
		col++;
	}
	printf(" %s", right);
}

static void	m44_print_bop_row(t_m44_bop_disp *d, int row,
		const char *left, const char *right)
{
	m44_print_mat_row(&d->m[0], row, left, right);
	printf(" ");
	if (row == 1)
		printf("%s", d->bop);
	else
		printf("%*s", (int)strlen(d->bop), "");
	printf(" ");
	m44_print_mat_row(&d->m[1], row, left, right);
	if (row == 1)
		printf(" = ");
	else
		printf("   ");
	m44_print_mat_row(&d->m[2], row, left, right);
	printf("\n");
}

static void	m44_print_bop(t_m44_bop_disp *d)
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
		m44_print_bop_row(d, row, left[row], right[row]);
		row++;
	}
}

void	m44_prt_bop(t_cpm44 m1, t_cpm44 m2, t_cpm44 m3, const char *bop)
{
	t_m44_bop_disp	d;

	if (!m1 || !m2 || !m3 || !bop)
		return ;
	d.bop = bop;
	m44_fill_mat(m1, d.m[0].b, d.m[0].w);
	m44_fill_mat(m2, d.m[1].b, d.m[1].w);
	m44_fill_mat(m3, d.m[2].b, d.m[2].w);
	m44_print_bop(&d);
}
