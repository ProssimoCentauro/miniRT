/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:46:36 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/05 08:48:30 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	random_value(uint32_t *state)
{
	uint32_t	result;

	*state = *state * 747796405 + 2891336453;
	result = ((*state >> ((*state >> 28) + 4)) ^ *state) * 277803737;
	result = (result >> 22) ^ result;
	return (result / 4294967295.0);
}

/* questo logaritmo costa un fottio da solo tipo il 7% del rendering*/
static float	random_value_normal_distribution(uint32_t *state)
{
	float	theta;
	float	rho;

	theta = 2 * PI * random_value(state);
	rho = sqrt(-2 * log(random_value(state)));
	return (rho * cos(theta));
}

static t_vector	random_direction(uint32_t *state)
{
	t_vector	random_vec;

	random_vec.x = random_value_normal_distribution(state);
	random_vec.y = random_value_normal_distribution(state);
	random_vec.z = random_value_normal_distribution(state);
	return (vector_normalize(random_vec));
}

t_vector	random_semisphere_direction(t_vector normal)
{
	static uint32_t	state = SEED;
	t_vector		vec;

	vec = random_direction(&state);
	if (vector_dot(vec, normal) < 0)
		vec = vector_invert(vec);
	return (vec);
}
