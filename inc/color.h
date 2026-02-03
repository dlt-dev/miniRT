/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:12:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 16:20:01 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef struct color
{
	double	r;
	double	g;
	double	b;
	double	t;
}			t_color;

uint32_t	trgb_pack(const t_color *c);
t_color		trgb_unpack(uint32_t packed);

#endif