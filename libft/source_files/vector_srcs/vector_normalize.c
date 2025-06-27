/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:47:55 by ibrunial          #+#    #+#             */
/*   Updated: 2025/06/27 12:34:59 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_normalize(t_vector v)
{
	const double	len2 = v.x * v.x + v.y * v.y + v.z * v.z;
	const double	inv_len = 1.0 / sqrt(len2);

	v.x *= inv_len;
	v.y *= inv_len;
	v.z *= inv_len;
	return (v);
}
