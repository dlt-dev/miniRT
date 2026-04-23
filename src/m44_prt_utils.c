/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:23:59 by jdelattr          #+#    #+#             */
/*   Updated: 2026/04/23 11:25:41 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	m44_fmt_value(double value, char out[64])
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

void	m44_set_borders(char **left, char **right)
{
	left[0] = "╭";
	left[1] = "│";
	left[2] = "│";
	left[3] = "╰";
	right[0] = "╮";
	right[1] = "│";
	right[2] = "│";
	right[3] = "╯";
}

void	m44_fill_buf(const t_m44 *m, char buf[4][4][64])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			m44_fmt_value((*m)[row * 4 + col], buf[row][col]);
			col++;
		}
		row++;
	}
}

void	m44_fill_widths(char buf[4][4][64], int col_width[4])
{
	int	row;
	int	col;
	int	len;

	col = 0;
	while (col < 4)
	{
		col_width[col] = 0;
		row = 0;
		while (row < 4)
		{
			len = (int)strlen(buf[row][col]);
			if (len > col_width[col])
				col_width[col] = len;
			row++;
		}
		col++;
	}
}

void	m44_print_rows(char buf[4][4][64], int col_width[4])
{
	char	*left[4];
	char	*right[4];
	int		row;
	int		col;

	m44_set_borders(left, right);
	row = 0;
	while (row < 4)
	{
		printf("%s", left[row]);
		col = 0;
		while (col < 4)
		{
			printf(" %*s", col_width[col], buf[row][col]);
			col++;
		}
		printf(" %s\n", right[row]);
		row++;
	}
}
