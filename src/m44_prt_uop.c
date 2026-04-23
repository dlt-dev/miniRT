/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt_uop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:06:27 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 12:16:08 by jdelattr         ###   ########.fr       */
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

static void	m44_print_row_left(t_m44_uop_disp *d, int row,
		const char *left, const char *right)
{
	int		col;

	printf("%s", left);
	col = 0;
	while (col < 4)
	{
		printf(" %*s", d->w1[col], d->b1[row][col]);
		col++;
	}
	printf(" %s ", right);
	if (row == 1)
		printf("%s", d->uop);
	else
		printf("%*s", (int)strlen(d->uop), "");
}

static void	m44_print_row_right(t_m44_uop_disp *d, int row,
		const char *left, const char *right)
{
	int	col;

	printf(" %s", left);
	col = 0;
	while (col < 4)
	{
		printf(" %*s", d->w2[col], d->b2[row][col]);
		col++;
	}
	printf(" %s", right);
	if (row == 1)
		printf(" =");
	printf("\n");
}

static void	m44_print_uop(t_m44_uop_disp *d)
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
		m44_print_row_left(d, row, left[row], right[row]);
		m44_print_row_right(d, row, left[row], right[row]);
		row++;
	}
}

void	m44_prt_uop(const t_m44 *m1, const t_m44 *m2, const char *uop)
{
	t_m44_uop_disp	d;

	if (!m1 || !m2 || !uop)
		return ;
	d.uop = uop;
	m44_fill_mat(m1, d.b1, d.w1);
	m44_fill_mat(m2, d.b2, d.w2);
	m44_print_uop(&d);
}
