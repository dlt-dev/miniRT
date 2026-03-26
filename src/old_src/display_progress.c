/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_progress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:52:24 by cybourge          #+#    #+#             */
/*   Updated: 2026/01/30 16:52:32 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	display_progress(int i, int j)
{
	double			current_progress;
	static double	progress_floor = 0.0;

	current_progress = ((i * WIN_W + j + 1.0) / (double)(WIN_H * WIN_W));
	if (current_progress >= progress_floor)
	{
		progress_floor += 0.01;
		display_progressbar(current_progress);
	}
	if (i == WIN_H - 1 && j == WIN_W - 1)
	{
		display_progressbar(1.0);
		progress_floor = 0.0;
	}
}
