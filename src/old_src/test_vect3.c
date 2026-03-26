/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vect3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:41:55 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 16:41:44 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

static void	test_vect3_add(void)
{
	assert(vect3_equal(vect3_add((t_vect3){0, 0, 0}, (t_vect3){0, 0, 0}),
			(t_vect3){0, 0, 0}));
	assert(vect3_equal(vect3_add((t_vect3){1, 2, 3}, (t_vect3){4, 5, 6}),
			(t_vect3){5, 7, 9}));
	assert(vect3_equal(vect3_add((t_vect3){-1, -2, -3}, (t_vect3){1, 2, 3}),
			(t_vect3){0, 0, 0}));
	assert(vect3_equal(vect3_add((t_vect3){0.5, 0.5, 0.5}, (t_vect3){0.5, 0.5,
				0.5}), (t_vect3){1, 1, 1}));
}

static void	test_vect3_sub(void)
{
	assert(vect3_equal(vect3_sub((t_vect3){1, 2, 3}, (t_vect3){1, 2, 3}),
			(t_vect3){0, 0, 0}));
	assert(vect3_equal(vect3_sub((t_vect3){5, 7, 9}, (t_vect3){1, 2, 3}),
			(t_vect3){4, 5, 6}));
	assert(vect3_equal(vect3_sub((t_vect3){0, 0, 0}, (t_vect3){1, 1, 1}),
			(t_vect3){-1, -1, -1}));
	assert(vect3_equal(vect3_sub((t_vect3){0.5, 0.5, 0.5}, (t_vect3){0.25, 0.25,
				0.25}), (t_vect3){0.25, 0.25, 0.25}));
}

static void	test_vect3_inv(void)
{
	assert(vect3_equal(vect3_inv((t_vect3){0, 0, 0}), (t_vect3){0, 0, 0}));
	assert(vect3_equal(vect3_inv((t_vect3){1, 2, 3}), (t_vect3){-1, -2,
			-3}));
	assert(vect3_equal(vect3_inv((t_vect3){-1, -2, -3}), (t_vect3){1, 2,
			3}));
	assert(vect3_equal(vect3_inv((t_vect3){0.5, -1, 2}), (t_vect3){-0.5, 1,
			-2}));
}

static void	test_vect3_length_squared(void)
{
	assert(double_equal(vect3_length_squared((t_vect3){0, 0, 0}), 0));
	assert(double_equal(vect3_length_squared((t_vect3){1, 0, 0}), 1));
	assert(double_equal(vect3_length_squared((t_vect3){1, 2, 2}), 9));
	assert(double_equal(vect3_length_squared((t_vect3){0.5, 0.5, 0.5}), 0.75));
}

static void	test_vect3_norm(void)
{
	assert(double_equal(vect3_norm((t_vect3){0, 0, 0}), 0));
	assert(double_equal(vect3_norm((t_vect3){3, 4, 0}), 5));
	assert(double_equal(vect3_norm((t_vect3){-3, -4, 0}), 5));
	assert(double_equal(vect3_norm((t_vect3){1, 2, 2}), 3));
}

static void	test_vect3_dot(void)
{
	assert(double_equal(vect3_dot((t_vect3){0, 0, 0}, (t_vect3){1, 2, 3}), 0));
	assert(double_equal(vect3_dot((t_vect3){1, 0, 0}, (t_vect3){1, 0, 0}), 1));
	assert(double_equal(vect3_dot((t_vect3){1, 2, 3}, (t_vect3){4, 5, 6}), 32));
	assert(double_equal(vect3_dot((t_vect3){1, 0, 0}, (t_vect3){0, 1, 0}), 0));
}

static void	test_vect3_cross(void)
{
	assert(vect3_equal(vect3_cross((t_vect3){1, 0, 0}, (t_vect3){0, 1, 0}),
			(t_vect3){0, 0, 1}));
	assert(vect3_equal(vect3_cross((t_vect3){0, 1, 0}, (t_vect3){1, 0, 0}),
			(t_vect3){0, 0, -1}));
	assert(vect3_equal(vect3_cross((t_vect3){1, 2, 3}, (t_vect3){4, 5, 6}),
			(t_vect3){-3, 6, -3}));
	assert(vect3_equal(vect3_cross((t_vect3){1, 1, 1}, (t_vect3){1, 1, 1}),
			(t_vect3){0, 0, 0}));
}

static void	test_vect3_mul_scalar(void)
{
	assert(vect3_equal(vect3_mul_scalar((t_vect3){1, 2, 3}, 2), (t_vect3){2, 4,
			6}));
	assert(vect3_equal(vect3_mul_scalar((t_vect3){1, 2, 3}, 0), (t_vect3){0, 0,
			0}));
	assert(vect3_equal(vect3_mul_scalar((t_vect3){-1, 2, -3}, -1), (t_vect3){1,
			-2, 3}));
	assert(vect3_equal(vect3_mul_scalar((t_vect3){0.5, 0.5, 0.5}, 2),
			(t_vect3){1, 1, 1}));
}

static void	test_vect3_div_scalar(void)
{
	assert(vect3_equal(vect3_div_scalar((t_vect3){2, 4, 6}, 2), (t_vect3){1, 2,
			3}));
	assert(vect3_equal(vect3_div_scalar((t_vect3){0, 0, 0}, 1), (t_vect3){0, 0,
			0}));
	assert(vect3_equal(vect3_div_scalar((t_vect3){-2, 4, -6}, -2), (t_vect3){1,
			-2, 3}));
	assert(vect3_equal(vect3_div_scalar((t_vect3){1, 1, 1}, 0.5), (t_vect3){2,
			2, 2}));
}

static void	test_vect3_unit(void)
{
	t_vect3	u;

	u = vect3_unit((t_vect3){3, 0, 0});
	assert(vect3_equal(u, (t_vect3){1, 0, 0}));
	u = vect3_unit((t_vect3){0, 4, 0});
	assert(vect3_equal(u, (t_vect3){0, 1, 0}));
	u = vect3_unit((t_vect3){0, 0, 0});
	assert(vect3_equal(u, (t_vect3){0, 0, 0}));
	u = vect3_unit((t_vect3){1, 2, 2});
	assert(double_equal(vect3_norm(u), 1));
}

int	main(void)
{
	test_vect3_add();
	test_vect3_sub();
	test_vect3_inv();
	test_vect3_length_squared();
	test_vect3_norm();
	test_vect3_dot();
	test_vect3_cross();
	test_vect3_mul_scalar();
	test_vect3_div_scalar();
	test_vect3_unit();
	printf("All vect3 tests passed ✅\n");
	return (0);
}
