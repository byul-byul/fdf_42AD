/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:17:12 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 19:30:44 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	interpolate_color(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = ((COLOR_MAX >> 16) & COLOR_MASK) * ratio + \
		((COLOR_MIN >> 16) & COLOR_MASK) * (1 - ratio);
	g = ((COLOR_MAX >> 8) & COLOR_MASK) * ratio + \
		((COLOR_MIN >> 8) & COLOR_MASK) * (1 - ratio);
	b = (COLOR_MAX & COLOR_MASK) * ratio + \
		(COLOR_MIN & COLOR_MASK) * (1 - ratio);
	return ((r << 16) | (g << 8) | b);
}
