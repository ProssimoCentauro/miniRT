/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:30:25 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/18 11:21:21 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* solve the equation and fill the t with the minumum positive solution*/
bool	equation_solve(t_equation *eq)
{
	double	discriminant;

	discriminant = eq->b * eq->b - 4 * eq->a * eq->c;
	if (discriminant < EPSILON)
		return (false);
	discriminant = sqrt(discriminant);
	eq->t = (-eq->b - discriminant) / (eq->a * 2);
	if (eq->t < EPSILON)
		eq->t = (-eq->b + discriminant) / (eq->a * 2);
	if (eq->t < EPSILON)
		return (false);
	return (true);
}
