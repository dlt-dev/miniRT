/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_m44.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:39:37 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 15:04:35 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"

#include <assert.h>
#include <stdio.h>

/*
// Fill matrix with sequential values
void fill_seq(t_m44 *m)
{
    for (int i = 0; i < 16; i++)
        (*m)[i] = i + 1;
}

void m44_print(const t_m44 *m)
{
    if (!m)
    {
        printf("(null matrix)\n");
        return;
    }

    for (int i = 0; i < M44_SIZE; i++)
    {
        for (int j = 0; j < M44_SIZE; j++)
        {
            printf("%8.3f ", (*m)[i * M44_SIZE + j]);
        }
        printf("\n");
    }
}

// -------------------- TESTS --------------------

void test_m44_zro()
{
    t_m44 m;
    m44_zro(&m);
    for (int i = 0; i < 16; i++)
        assert(m[i] == 0.0);
}

void test_m44_eql()
{
    t_m44 a, b;
    fill_seq(&a);
    fill_seq(&b);
    assert(m44_eql(&a, &b) == true);

    b[0] += 1;
    assert(m44_eql(&a, &b) == false);
}

void test_m44_ele()
{
    t_m44 m;
    fill_seq(&m);

    double val;
    assert(m44_ele(&m, 1, 2, &val) == 0);
    assert(val == m[1 * 4 + 2]);

    assert(m44_ele(&m, 5, 0, &val) == -1); // invalid index
}

void test_m44_cpy()
{
    t_m44 a, b;
    fill_seq(&a);
    m44_cpy(&a, &b);
    assert(m44_eql(&a, &b));
}

void test_m44_add_sub()
{
    t_m44 a, b, res;

    fill_seq(&a);
    fill_seq(&b);

    m44_add(&a, &b, &res);
    for (int i = 0; i < 16; i++)
        assert(res[i] == 2 * a[i]);

    m44_sub(&res, &a, &res);
    assert(m44_eql(&res, &a));
}

void test_m44_mul()
{
    t_m44 a, res;
    fill_seq(&a);

    m44_mul(&a, 2.0, &res);
    for (int i = 0; i < 16; i++)
        assert(res[i] == a[i] * 2.0);
}

void test_m44_idm()
{
    t_m44 id;
    m44_idm(&id);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            assert(id[i * 4 + j] == (i == j ? 1.0 : 0.0));
}

void test_m44_prd()
{
    t_m44 id, a, res;

    m44_idm(&id);
    fill_seq(&a);

    m44_prd(&a, &id, &res);
    assert(m44_eql(&a, &res));
}

void test_m44_trp()
{
    t_m44 a, res;
    fill_seq(&a);

    m44_trp(&a, &res);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            assert(res[i * 4 + j] == a[j * 4 + i]);
}

void test_m44_inv_product_identity()
{
    t_m44 a = {
        4, 7, 2, 0,
        3, 6, 1, 0,
        2, 5, 1, 0,
        0, 0, 0, 1
    }; // Non-singular matrix

    t_m44 inv;
    t_m44 prod;
    t_m44 id;

    assert(m44_inv(&a, &inv) == 0);
    assert(m44_prd(&a, &inv, &prod) == 0);
    assert(m44_idm(&id) == 0);

   assert(m44_eql(&prod, &id) == true);
}

void test_m44_inv_singular()
{
    t_m44 singular = {
        1, 2, 3, 4,
        2, 4, 6, 8,  // ← row2 = 2 * row1
        1, 0, 1, 0,
        0, 0, 0, 1
    };

    t_m44 inv;

    assert(m44_inv(&singular, &inv) == -1);
}

void test_m44_inv_identity()
{
    t_m44 id, inv;
    m44_idm(&id);

    assert(m44_inv(&id, &inv) == 0);
    assert(m44_eql(&id, &inv));
}

void test_m44_inv_scaling()
{
    t_m44 scl = {
        2,0,0,0,
        0,3,0,0,
        0,0,4,0,
        0,0,0,1
    };
    t_m44 inv;

    m44_inv_scl(&scl, &inv);

    assert(deql(inv[0], 0.5));
    assert(deql(inv[5], 1.0/3.0));
    assert(deql(inv[10], 0.25));
}

void test_m44_inv_translation()
{
    t_m44 trl = {
        1,0,0,5,
        0,1,0,6,
        0,0,1,7,
        0,0,0,1
    };
    t_m44 inv;

    m44_inv_trl(&trl, &inv);

    assert(inv[3] == -5);
    assert(inv[7] == -6);
    assert(inv[11] == -7);
}

void test_m44_inv_rot()
{
    // simple 90° rotation around Z
    t_m44 rot = {
        0,-1,0,0,
        1, 0,0,0,
        0, 0,1,0,
        0, 0,0,1
    };
    t_m44 inv, trp;

    m44_inv_rot(&rot, &inv);
    m44_trp(&rot, &trp);

    assert(m44_eql(&inv, &trp)); // rotation inverse = transpose
}

// -------------------- MAIN --------------------

int main(void)
{
	printf("===== Part 1 =====\n");
    test_m44_zro();
    test_m44_eql();
    test_m44_ele();
    test_m44_cpy();
	printf("Good\n");
	printf("===== Part 2 =====\n");
    test_m44_add_sub();
    test_m44_mul();
    test_m44_prd();
    test_m44_idm();
    test_m44_trp();
	printf("Good\n");
	printf("===== Part 3 =====\n");
	test_m44_inv_product_identity();
	test_m44_inv_singular();
    test_m44_inv_identity();
    test_m44_inv_scaling();
    test_m44_inv_translation();
    test_m44_inv_rot();
	printf("Good\n");
    printf("All tests passed!\n");
    return 0;
}
*/