/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_project.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:48:31 by ibrunial          #+#    #+#             */
/*   Updated: 2025/06/27 10:47:24 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector3_project(t_vector vec1, t_vector vec2)
{
	double	dot;
	double	b_len_sq;
	double	scale;

	dot = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	b_len_sq = vec2.x * vec2.x + vec2.y * vec2.y + vec2.z * vec2.z;
	if (b_len_sq == 0.0f)
		return ((t_vector){0, 0, 0});
	scale = dot / b_len_sq;
	return ((t_vector){vec2.x * scale, vec2.y * scale, vec2.z * scale});
}
