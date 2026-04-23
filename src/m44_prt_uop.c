/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt_uop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:06:27 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 11:30:02 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*typedef struct s_m44_uop_disp
{
	char	b1[4][4][64];
	int		w1[4];
	char	b2[4][4][64];
	int		w2[4];
	char	const	*uop;
}t_m44_uop_disp;*/

// void	m44_prt_uop(const t_m44 *m1, const t_m44 *m2, const char *uop)
// {
// 	const int	pad_len = strlen(uop);

// 	if (!m1 || !m2 || !uop)
// 		return ;
// 	printf(
// 		"%*s ╭ %8.3f %8.3f %8.3f %8.3f ╮   ╭ %8.3f %8.3f %8.3f %8.3f ╮\n"
// 		"%s │ %8.3f %8.3f %8.3f %8.3f │ = │ %8.3f %8.3f %8.3f %8.3f │\n"
// 		"%*s │ %8.3f %8.3f %8.3f %8.3f │   │ %8.3f %8.3f %8.3f %8.3f │\n"
// 		"%*s ╰ %8.3f %8.3f %8.3f %8.3f ╯   ╰ %8.3f %8.3f %8.3f %8.3f ╯\n",
// 		pad_len, "",
// 		(*m1)[0], (*m1)[1], (*m1)[2], (*m1)[3],
// 		(*m2)[0], (*m2)[1], (*m2)[2], (*m2)[3],
// 		uop,
// 		(*m1)[4], (*m1)[5], (*m1)[6], (*m1)[7],
// 		(*m2)[4], (*m2)[5], (*m2)[6], (*m2)[7],
// 		pad_len, "",
// 		(*m1)[8], (*m1)[9], (*m1)[10], (*m1)[11],
// 		(*m2)[8], (*m2)[9], (*m2)[10], (*m2)[11],
// 		pad_len, "",
// 		(*m1)[12], (*m1)[13], (*m1)[14], (*m1)[15],
// 		(*m2)[12], (*m2)[13], (*m2)[14], (*m2)[15]
// 		);
// }

/*static void	m44_fmt_value(double value, char out[64])
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
}*/

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
