/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_progress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:52:24 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 09:54:57 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	display_progress(int i, int j)
{
	double			current_progress;
	static double	progress_floor = 0.0;

	current_progress = ((i + j * WIN_W) / (double)(WIN_H * WIN_W));
	if (current_progress >= progress_floor)
	{
		progress_floor += 0.01;
		display_progressbar(current_progress);
	}
	if ((i + 1) * (j + 1) == WIN_H * WIN_W)
	{
		display_progressbar(1.0);
		progress_floor = 0.0;
	}
}
