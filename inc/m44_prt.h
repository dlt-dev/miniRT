/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:39:30 by jdelattr          #+#    #+#             */
/*   Updated: 2026/04/23 10:56:25 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




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
