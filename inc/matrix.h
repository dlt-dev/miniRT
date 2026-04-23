/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:07:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 11:24:34 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "utils.h"
# include "vector4.h"
# include <stdbool.h>
# include <stddef.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

# define M44_SIZE 4

// bop
typedef struct s_m44_mat_disp
{
	char	b[4][4][64];
	int		w[4];
}t_m44_mat_disp;

typedef struct s_m44_bop_disp
{
	t_m44_mat_disp	m[3];
	char	const	*bop;
}t_m44_bop_disp;

// uop
typedef struct s_m44_uop_disp
{
	char	b1[4][4][64];
	int		w1[4];
	char	b2[4][4][64];
	int		w2[4];
	char	const	*uop;
}t_m44_uop_disp;

// vprd
typedef struct s_m44_vprd_disp
{
	char	m_buf[4][4][64];
	int		m_w[4];
	char	v1_buf[4][64];
	char	v2_buf[4][64];
	int		v_w[2];
}t_m44_vprd_disp;





typedef double	t_m44[M44_SIZE * M44_SIZE];

// Exists the shorten function prototypes due to the 42 norm.
typedef const t_m44* t_cpm44;

// UTILITY FUNCTIONS
// Zeroes the Matrix, returns -1 on error, 0 otherwise.
int		m44_zro(t_m44 *m1);
// Matrix Equality
bool	m44_eql(const t_m44 *m1, const t_m44 *m2);
// Access Matrix Element M(i,j), returns -1 on error, 0 otherwise.
int		m44_ele(const t_m44 *m1, unsigned int i, unsigned int j, double *ele);
// Copies the Matrix, returns -1 on error, 0 otherwise.
int		m44_cpy(const t_m44 *m1, t_m44 *res);
// Prints the Matrix row by row.
void	m44_prt(const t_m44 *m1);
// Prints the Matrixes as : m1 (Binary Operator or Operation) m2 = m3.
void	m44_prt_bop(t_cpm44 m1, t_cpm44 m2, t_cpm44 m3, const char *bop);
// Prints the Matrixes as : (Unary Operator or Operation) m1  = m2.
void	m44_prt_uop(const t_m44 *m1, const t_m44 *m2, const char *uop);
// Prints the Matrix Vector product as : m1 * v1 = v2.
void	m44_prt_vprd(const t_m44 *m1, const t_v4 *v1, const t_v4 *v2);

// ARITHMETIC FUNCTIONS
// Matrix Addition, returns -1 on error, 0 otherwise.
int		m44_add(const t_m44 *m1, const t_m44 *m2, t_m44 *res);
// Matrix Substraction, returns -1 on error, 0 otherwise.
int		m44_sub(const t_m44 *m1, const t_m44 *m2, t_m44 *res);
// Matrix Scalar Multiplication, returns -1 on error, 0 otherwise.
int		m44_mul(const t_m44 *m1, double scalar, t_m44 *res);
// Matrix Product : m1 * m2, returns -1 on error, 0 otherwise.
int		m44_prd(const t_m44 *m1, const t_m44 *m2, t_m44 *res);
// Matrix Vector Product, returns -1 on error, 0 otherwise.
int		m44_vprd(const t_m44 *m1, const t_v4 *v1, t_v4 *res);
// Matrix Inverse using Gauss-Jordan, returns -1 on error, 0 otherwise.
int		m44_inv(const t_m44 *m1, t_m44 *res);
// Identity Matrix, returns -1 on error, 0 otherwise.
int		m44_idm(t_m44 *res);
// Transpose Matrix, returns -1 on error, 0 otherwise.
int		m44_trp(const t_m44 *m1, t_m44 *res);

// RAYTRACING SPECIFIC FUNCTIONS
// Inverse of Translation matrix, returns -1 on error, 0 otherwise.
int		m44_inv_trl(const t_m44 *m1, t_m44 *res);
// Inverse of Rotation matrix, returns -1 on error, 0 otherwise.
int		m44_inv_rot(const t_m44 *m1, t_m44 *res);
// Inverse of Scaling matrix, returns -1 on error, 0 otherwise.
int		m44_inv_scl(const t_m44 *m1, t_m44 *res);
// Inverse of a Shearing matrix, returns -1 on error, 0 otherwise.
int		m44_inv_she(const t_m44 *m1, t_m44 *res);


void	m44_print_rows(char buf[4][4][64], int col_width[4]);
void	m44_fill_widths(char buf[4][4][64], int col_width[4]);
void	m44_fill_buf(const t_m44 *m, char buf[4][4][64]);
void	m44_set_borders(char **left, char **right);
void	m44_fmt_value(double value, char out[64]);
#endif