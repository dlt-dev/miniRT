/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_v4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:57:56 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 12:07:54 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector4.h"
#include "utils.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
/*
int main(void)
{
    // Sample vectors for testing
    t_v4 a = v4_crt(1.0, 2.0, 3.0);
    t_v4 b = v4_crt(4.0, 5.0, 6.0);

    // ===== COMPARISON =====
    t_v4 a_copy = v4_crt(1.0, 2.0, 3.0);
    assert(v4_eql(a, a_copy));
    printf("v4_eql(a, a_copy) passed.\n");

    // ===== BASIC OPERATIONS =====
    t_v4 sum = v4_add(a, b);
    assert(v4_eql(sum, v4_crt(5.0, 7.0, 9.0)));
    v4_prt_bop(&a, &b, &sum, "+");

    t_v4 diff = v4_sub(b, a);
    assert(v4_eql(diff, v4_crt(3.0, 3.0, 3.0)));
    v4_prt_bop(&b, &a, &diff, "-");

    t_v4 inv_a = v4_inv(a);
    assert(v4_eql(inv_a, v4_crt(-1.0, -2.0, -3.0)));
    v4_prt_uop(&a, &inv_a, "inverse");

    // ===== LENGTH OPERATIONS =====
    double len_a_sq = v4_lsq(a);
    assert(deql(len_a_sq, 14.0));
    printf("v4_lsq(a) = %.2f\n", len_a_sq);

    double len_a = v4_len(a);
    assert(deql(len_a, 3.74165738677)); // sqrt(14)
    printf("v4_len(a) = %.10f\n", len_a);

    t_v4 uni_a = v4_uni(a);
    assert(deql(v4_len(uni_a), 1.0));
    v4_prt_uop(&a, &uni_a, "normal");

    // ===== PRODUCTS =====
    double dot_ab = v4_dot(a, b);
    assert(deql(dot_ab, 32.0)); // 1*4 + 2*5 + 3*6
    printf("v4_dot(a, b) = %.2f\n", dot_ab);

    t_v4 cross_ab = v4_xpr(a, b);
    assert(v4_eql(cross_ab, v4_crt(-3.0, 6.0, -3.0)));
    v4_prt_bop(&a, &b, &cross_ab, "x");

    // ===== SCALAR OPERATIONS =====
    t_v4 a_mul_2 = v4_mul(a, 2.0);
    assert(v4_eql(a_mul_2, v4_crt(2.0, 4.0, 6.0)));
    v4_prt_uop(&a, &a_mul_2, "2 *");

    t_v4 b_div_2 = v4_div(b, 2.0);
    assert(v4_eql(b_div_2, v4_crt(2.0, 2.5, 3.0)));
    v4_prt_uop(&b, &b_div_2, "1/2 *");

    printf("All tests passed!\n");
    return 0;
}
*/