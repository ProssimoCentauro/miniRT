/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:42:10 by ibrunial          #+#    #+#             */
/*   Updated: 2025/06/23 21:48:55 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

void		vector_set_zero(t_vector *vec);
t_vector	vector_add(t_vector vec1, t_vector vec2);
t_vector	vector_add3(t_vector vec1, t_vector vec2, t_vector vec3);
t_vector	vector_add4(t_vector vec1, t_vector vec2, t_vector vec3, t_vector vec4);
t_vector	vector_sub(t_vector vec1, t_vector vec2);
double		vector_dot(t_vector vec1, t_vector vec2);
t_vector	vector_cross(t_vector vec1, t_vector vec2);
double		vector_lenght(t_vector vec);
double		vector_lenght_squared(t_vector vec);
t_vector	vector_normalize(t_vector vec);
t_vector	vector_project(t_vector vec1, t_vector vec2);
t_vector    vector_scale(t_vector vec, double scale);
t_vector    vector_invert(t_vector vec);

#endif