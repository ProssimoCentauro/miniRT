/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:07 by ibrunial          #+#    #+#             */
/*   Updated: 2025/10/11 16:21:47 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_object(const t_object *o)
{
	if (!o)
		return ;
	printf(BOLD_YELLOW "Object type: %s\n" RESET, type_name(o->type));
	if (o->type == SPHERE)
		print_sphere(&o->figure.sphere);
	else if (o->type == PLANE)
		print_plane(&o->figure.plane);
	else if (o->type == CYLINDER)
		print_cylinder(&o->figure.cylinder);
	else if (o->type == CONE)
		print_cone(&o->figure.cone);
	else
		printf("  [No detailed printer implemented]\n");
}

void	print_camera(const t_camera *c)
{
	if (!c)
		return ;
	printf(BOLD_CYAN "=== Camera ===\n" RESET);
	printf("Coord: ");
	print_vec(c->coord);
	printf("\nOrientation: ");
	print_vec(c->orientation);
	printf("\nFOV: %.2f\n\n", c->fov);
}

void	print_ambient(const t_ambient *a)
{
	if (!a)
		return ;
	printf(BOLD_MAGENTA "=== Ambient Light ===\n" RESET);
	printf("Ratio: %.2f\nColor: ", a->ratio);
	print_rgb(a->rgb);
	printf("\n\n");
}

void	print_lights(const t_light *lst)
{
	int	i;

	printf(BOLD_GREEN "=== Lights ===\n" RESET);
	i = 0;
	while (lst)
	{
		printf("Light %d:\n", i);
		printf("  Coord: ");
		print_vec(lst->coord);
		printf("\n  Brightness: %.2f\n  Color: ", lst->brightness);
		print_rgb(lst->rgb);
		printf("\n\n");
		lst = lst->next;
		i++;
	}
}

void	print_objects(const t_object *lst)
{
	int	i;

	printf(BOLD_YELLOW "=== Objects ===\n" RESET);
	i = 0;
	while (lst)
	{
		printf("Object %d:\n", i);
		print_object(lst);
		printf("\n");
		lst = lst->next;
		i++;
	}
}
