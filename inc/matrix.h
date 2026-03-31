/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:07:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 10:57:45 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "utils.h"
# include <stdbool.h>

# define M44_SIZE 4

typedef double	t_m44[M44_SIZE * M44_SIZE];

// GENERIC UTILITY FUNCTIONS
// Zeroes the Matrix, returns -1 on error, 0 otherwise.
int		m44_zro(t_m44 *m1);
// Matrix Equality
bool	m44_eql(const t_m44 *m1, const t_m44 *m2);
//Access Matrix Element M(i,j), returns -1 on error, 0 otherwise.
int		m44_ele(const t_m44 *m1, unsigned int i, unsigned int j, double *ele);
// Matrix Addition, returns -1 on error, 0 otherwise.
int		m44_add(const t_m44 *m1, const t_m44 *m2, t_m44 *res);
// Matrix Substraction, returns -1 on error, 0 otherwise.
int		m44_sub(const t_m44 *m1, const t_m44 *m2, t_m44 *res);
// Matrix Scalar Multiplication, returns -1 on error, 0 otherwise.
int		m44_mul(const t_m44 *m1, double scalar, t_m44 *res);
// Matrix Product, returns -1 on error, 0 otherwise.
int		m44_prd(const t_m44 *m1, const t_m44 *m2, t_m44 *res);
// Matrix Inverse using Gauss-Jordan, returns -1 on error, 0 otherwise.
int		m44_inv(const t_m44 *m1, t_m44 *res);
// Identity Matrix, returns -1 on error, 0 otherwise.
int		m44_idm(t_m44 *res);

// RAYTRACING SPECIFIC FUNCTIONS
// Inverse of Translation matrix.
// Inverse of Rotation matrix.
// Inverse of Scaling matrix.

#endif