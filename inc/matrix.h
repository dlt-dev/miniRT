/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:07:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:08:21 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "utils.h"
# include <sys/types.h>
# include <stdlib.h>

typedef struct matrix
{
	unsigned int	r;
	unsigned int	c;
	double			*m;
}	t_mat;

// Allocates the m field of Matrix using its r and c as parameters.
t_mat	*mat_crt(t_mat *m1);
// Frees the m field of Matrix.
void	mat_dlt(t_mat *mat);
// Matrix Equality
bool	mat_eql(const t_mat *m1, const t_mat *m2);
//Access Matrix Element M(i,j), returns -1 on error, 0 otherwise.
int		mat_ele(const t_mat *m1, unsigned int i, unsigned int j, double *ele);
// Matrix Addition, returns -1 on error, 0 otherwise.
int		mat_add(const t_mat *m1, const t_mat *m2, t_mat *res);
// Matrix Substraction, returns -1 on error, 0 otherwise.
int		mat_sub(const t_mat *m1, const t_mat *m2, t_mat *res);
// Matrix Scalar Multiplication, returns -1 on error, 0 otherwise.
int		mat_mul(const t_mat *m1, double scalar, t_mat *res);
// Matrix Product, returns -1 on error, 0 otherwise.
int		mat_prd(const t_mat *m1, const t_mat *m2, t_mat *res);
// Matrix Inverse, returns -1 on error, 0 otherwise.
int		mat_inv(const t_mat *m1, t_mat *res);
// Identity Matrix, returns -1 on error, 0 otherwise.
int		mat_idm(const t_mat *m1, t_mat *res);
// Sets subject to the size of model
int		mat_set(const t_mat *model, t_mat *subject);

#endif