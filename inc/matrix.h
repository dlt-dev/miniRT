/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:07:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 12:28:17 by cybourge         ###   ########.fr       */
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
// Prints the Matrixes as : m1 (Binary Operator) m2 = m3.
void	m44_prt_bop(t_cpm44 m1, t_cpm44 m2, t_cpm44 m3, const char *bop);
// Prints the Matrixes as : (Unary Operator / Operation) m1  = m2.
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
// Matrix Product, returns -1 on error, 0 otherwise.
int		m44_prd(const t_m44 *m1, const t_m44 *m2, t_m44 *res);
// Matrix Vector Product, returns -1 on error, 0 otherwise.
int		m44_vprd(const t_m44 *m1, const t_v4 *v1, t_v4 *res);
// Matrix Inverse using Gauss-Jordan, returns -1 on error, 0 otherwise.
int		m44_inv(const t_m44 *m1, t_m44 *res);
// Identity Matrix, returns -1 on error, 0 otherwise.
int		m44_idm(t_m44 *res);
// Transpose Matrix, return -1 on error, 0 otherwise.
int		m44_trp(const t_m44 *m1, t_m44 *res);

// RAYTRACING SPECIFIC FUNCTIONS
// Inverse of Translation matrix, return -1 on error, 0 otherwise.
int		m44_inv_trl(const t_m44 *m1, t_m44 *res);
// Inverse of Rotation matrix, return -1 on error, 0 otherwise.
int		m44_inv_rot(const t_m44 *m1, t_m44 *res);
// Inverse of Scaling matrix, return -1 on error, 0 otherwise.
int		m44_inv_scl(const t_m44 *m1, t_m44 *res);

#endif