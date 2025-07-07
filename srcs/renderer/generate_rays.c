/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:01:23 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/05 08:39:51 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	generate_rays(t_renderer *renderer, int iteration)
{
	const float focal_length = 0.5; // forse non è necessario sia una variabile, o una constante o non necessaria
	float viewport_height = 2.0f * tan((renderer->scene->cam->fov * 0.5f) // altezza del piano
			* PI / 180.0f); 
	float viewport_width = viewport_height * ((double)renderer->mlx->width // larghezza del piano
			/ renderer->mlx->height);

    /* cambio di sistema di riferimento, calcolo degli assi ortonormali alla camera orientation*/
	t_vector camera_dir = vector_normalize((renderer->scene->cam->orientation));
    t_vector camera_right = vector_normalize(vector_cross((t_vector){0, 1, 0}, camera_dir));
    t_vector camera_up = vector_normalize(vector_cross(camera_dir, camera_right));

    /* calcolo dei delta_x e delta_y sul piano*/
	t_vector px_step = vector_scale(camera_right, viewport_width
			/ renderer->mlx->width);
	t_vector py_step = vector_scale(camera_up, -viewport_height
			/ renderer->mlx->height);

    /* caolcolo del vettore posizione in alto a sinistra (lo userò per calcolare dopo tutti gli altri)*/
    t_vector forward = vector_scale(camera_dir, focal_length);

	t_vector upper_left = vector_add4((renderer->scene->cam->coord), forward,
			vector_scale(camera_right, -viewport_width * 0.5f + 0.5f
				* (viewport_width / renderer->mlx->width)),
			vector_scale(camera_up, viewport_height * 0.5f - 0.5f
				* (viewport_height / renderer->mlx->height)));

    /* loop */
	for (int y = 0; y < renderer->mlx->height; ++y)
	{
        /* precalcolo l'offeet delle y per tutti gli x*/
		t_vector row_start = vector_add(upper_left, vector_scale(py_step, y));
		for (int x = 0; x < renderer->mlx->width; ++x)
		{
            /* calcolo il versore (normalizzato) del raggio per il pixel*/
			t_ray ray;
			ray.direction = vector_add(row_start, vector_scale(px_step, x));
			ray.direction = vector_normalize(vector_sub(ray.direction,
						renderer->scene->cam->coord));

            /* probabilmente non serve fare una cosa del genere, il ray.coord è sempre la cam pos*/
			ray.coord = renderer->scene->cam->coord;

            /* per ora restituisce rosso se è stato colpito nero altrimenti*/
			t_color color = follow_ray(renderer->scene, &ray);
            unsigned int argb;
            /* coloro il pixel*/
            if (iteration >= 1)
            {
                t_color screen_color = convert_rgb((t_rgb)*(unsigned int *)(renderer->mlx->image.addr + y
					* renderer->mlx->image.line_length + x
					* (renderer->mlx->image.bits_per_pixel >> 3)));
                argb = convert_color(mean_color(screen_color, iteration, color)).rgb;
            }
            else
            {
                color = add_color(color, multiply_color_scalar(renderer->scene->amb->color, renderer->scene->amb->ratio));
			    argb = convert_color(color).rgb;
            }
			*(unsigned int *)(renderer->mlx->image.addr + y
					* renderer->mlx->image.line_length + x
					* (renderer->mlx->image.bits_per_pixel >> 3)) = argb;
            
            printf("\r\033[K%.2lf%%", (double)(renderer->mlx->height * y + x + 1) / (renderer->mlx->height * renderer->mlx->width) * 100);
            fflush(stdout);
            /* non dovrebbe stare qua ma per ora lo lascio (forse meglio mettere ray.hit sullo stack e non come puntatore)*/
		}
	}
}
