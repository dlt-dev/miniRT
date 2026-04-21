/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt_uop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:06:27 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/21 08:42:07 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

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

static void	m44_print_uop(char b1[4][4][64], int w1[4],
		char b2[4][4][64], int w2[4], const char *uop)
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
			printf(" %*s", w1[col], b1[row][col]);
			col++;
		}
		printf(" %s ", right[row]);
		if (row == 1)
			printf("%s", uop);
		else
			printf("%*s", (int)strlen(uop), "");
		printf(" %s", left[row]);
		col = 0;
		while (col < 4)
		{
			printf(" %*s", w2[col], b2[row][col]);
			col++;
		}
		printf(" %s", right[row]);
		if (row == 1)
			printf(" =");
		printf("\n");
		row++;
	}
}

void	m44_prt_uop(const t_m44 *m1, const t_m44 *m2, const char *uop)
{
	char	b1[4][4][64];
	char	b2[4][4][64];
	int		w1[4];
	int		w2[4];

	if (!m1 || !m2 || !uop)
		return ;
	m44_fill_mat(m1, b1, w1);
	m44_fill_mat(m2, b2, w2);
	m44_print_uop(b1, w1, b2, w2, uop);
}
