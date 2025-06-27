/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:08:25 by ibrunial          #+#    #+#             */
/*   Updated: 2025/06/27 10:47:32 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector    vector_scale(t_vector vec, double scale)
{
    return ((t_vector){vec.x * scale, vec.y * scale, vec.z * scale});
}