/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_v3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:22:22 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 09:27:30 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

// ---------------------------------
// TESTS
// ---------------------------------

static void	test_deql(void)
{
	assert(deql(1.0, 1.0));
	assert(deql(1.0, 1.0 + 1e-10));
	assert(!deql(1.0, 1.1));
}

static void	test_v3_eql(void)
{
	t_v3 a = {1, 2, 3};
	t_v3 b = {1, 2, 3};
	t_v3 c = {1, 2, 3.00000000000001};

	assert(v3_eql(a, b));
	assert(v3_eql(a, c));
	assert(!v3_eql(a, (t_v3){0, 0, 0}));
}

static void	test_basic_ops(void)
{
	t_v3 a = {1, 2, 3};
	t_v3 b = {4, 5, 6};

	v3_eql(v3_add(a, b), (t_v3){5, 7, 9});
	v3_eql(v3_sub(a, b), (t_v3){-3, -3, -3});
	v3_eql(v3_inv(a), (t_v3){-1, -2, -3});
}

static void	test_length(void)
{
	t_v3 v = {3, 4, 0};

	assert(deql(v3_lsq(v), 25.0));
	assert(deql(v3_len(v), 5.0));
}

static void	test_unit(void)
{
	t_v3 v = {0, 3, 4};
	t_v3 u = v3_uni(v);

	assert(deql(v3_len(u), 1.0));

	// zero vector edge case
	t_v3 zero = {0, 0, 0};
	v3_eql(v3_uni(zero), zero);
}

static void	test_dot(void)
{
	t_v3 a = {1, 2, 3};
	t_v3 b = {4, -5, 6};

	assert(deql(v3_dot(a, b), 12.0)); // 1*4 + 2*(-5) + 3*6 = 12
}

static void	test_cross(void)
{
	t_v3 a = {1, 0, 0};
	t_v3 b = {0, 1, 0};

	v3_eql(v3_xpr(a, b), (t_v3){0, 0, 1});
	v3_eql(v3_xpr(b, a), (t_v3){0, 0, -1});
}

static void	test_scalar_ops(void)
{
	t_v3 v = {1, -2, 3};

	v3_eql(v3_mul(v, 2.0), (t_v3){2, -4, 6});
	v3_eql(v3_div(v, 2.0), (t_v3){0.5, -1, 1.5});

	// division by ~0
	v3_eql(v3_div(v, 0.0), (t_v3){0, 0, 0});
}

// ---------------------------------
// MAIN
// ---------------------------------

int	main(void)
{
	test_deql();
	test_v3_eql();
	test_basic_ops();
	test_length();
	test_unit();
	test_dot();
	test_cross();
	test_scalar_ops();

	printf("All tests passed!\n");
	return (0);
}