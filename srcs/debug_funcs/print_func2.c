/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:08:47 by ibrunial          #+#    #+#             */
/*   Updated: 2025/10/11 16:09:52 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_sphere(const t_sphere *s)
{
	if (!s)
		return ;
	printf("  Coord: ");
	print_vec(s->coord);
	printf("\n  Diameter: %.2f\n  Color: ", s->diameter);
	print_rgb(s->rgb);
	printf("\n");
}

void	print_plane(const t_plane *p)
{
	if (!p)
		return ;
	printf("  Coord: ");
	print_vec(p->coord);
	printf("\n  Normal: ");
	print_vec(p->normal);
	printf("\n  Color: ");
	print_rgb(p->rgb);
	printf("\n");
}

void	print_cylinder(const t_cylinder *c)
{
	if (!c)
		return ;
	printf("  Coord: ");
	print_vec(c->coord);
	printf("\n  Normal: ");
	print_vec(c->normal);
	printf("\n  Diameter: %.2f\n  Height: %.2f\n  Color: ", c->diameter,
		c->height);
	print_rgb(c->rgb);
	printf("\n");
}

void	print_cone(const t_cone *c)
{
	if (!c)
		return ;
	printf("  Coord: ");
	print_vec(c->coord);
	printf("\n  Normal: ");
	print_vec(c->normal);
	printf("\n  Angle: %.2f°\n  Height: %.2f\n  Color: ", c->angle, c->height);
	print_rgb(c->rgb);
	printf("\n");
}
