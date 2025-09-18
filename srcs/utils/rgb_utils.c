/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:20:59 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/18 11:21:01 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	rgb_add(t_rgb a, t_rgb b)
{
	t_rgb	out;

	out.r = a.r + b.r;
	out.g = a.g + b.g;
	out.b = a.b + b.b;
	return (out);
}

t_rgb	rgb_scale(t_rgb a, double scale)
{
	t_rgb	out;

	out.r = (int)(a.r * scale);
	out.g = (int)(a.g * scale);
	out.b = (int)(a.b * scale);
	return (out);
}
