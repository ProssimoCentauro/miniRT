/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:52:52 by ibrunial          #+#    #+#             */
/*   Updated: 2025/06/27 12:15:06 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_add(t_vector vec1, t_vector vec2)
{
	return ((t_vector){vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z});
}

t_vector	vector_add3(t_vector vec1, t_vector vec2, t_vector vec3)
{
	return ((t_vector){vec1.x + vec2.x + vec3.x, vec1.y + vec2.y + vec3.y,
		vec1.z + vec2.z + vec3.z});
}

t_vector	vector_add4(t_vector vec1, t_vector vec2, t_vector vec3,
		t_vector vec4)
{
	return ((t_vector){vec1.x + vec2.x + vec3.x + vec4.x, vec1.y + vec2.y
		+ vec3.y + vec4.y, vec1.z + vec2.z + vec3.z + vec4.z});
}
