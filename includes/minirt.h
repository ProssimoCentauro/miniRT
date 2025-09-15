/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:52:54 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/15 15:38:49 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/header_files/vector.h"
# include "../minilibx-linux/mlx.h"
# include "defines.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "structures.h"
# include <assert.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// debug_utils.c
void		print_object_data(t_object_data obj);
void		print_scene(t_scene *scene);

// figures_funcs.c
t_object	*create_sphere(t_object_data *d);
t_object	*create_plane(t_object_data *d);
t_object	*create_cylinder(t_object_data *d);
t_object	*create_cone(t_object_data *d);

// environment_funcs.c
t_camera	*create_camera(t_object_data *d);
t_light		*create_light(t_object_data *d);
t_ambient	*create_ambient(t_object_data *d);

// general_funcs.c
t_type		create_from_data(t_object_data *d, void **out);

// general_parser_utils.c
size_t		count_lines(char **mat);
double		ft_atod(char *str);
void		modify_vector(t_vector *v, double num, int i);
void		modify_rgb(t_rgb *rgb, int num, int i);

// check_env_objs_utils.c
int			check_camera(char **line, t_renderer *r);
int			check_amb_light(char **line, t_renderer *r);
int			check_light(char **line, t_renderer *r);

// check_objs_utils.c
int			check_sphere(char **line, t_renderer *r);
int			check_plane(char **line, t_renderer *r);
int			check_cylinder(char **line, t_renderer *r);
int			check_cone(char **line, t_renderer *r);

// check_objs_params_utils_1.c
int			is_valid_integer(char *str);
int			is_valid_double(char *str, double *num);
int			is_valid_vector_range(char *str);

// check_objs_params_utils_2.c
int			check_ratio(char *ratio, double *num);
int			is_valid_rgb_component(char *str);
int			check_colors(char *line, t_rgb *colors);
int			check_coordinates(char *line, t_vector *coords);
int			check_normal(char *line, t_vector *normal);

// check_objs_params_utils_3.c
int			check_ratio(char *ratio, double *num);
int			check_fov(char *line, double *num);
int			is_valid_angle(char *line, double *num);

// scene_utils.c
void		add_object(t_scene *scene, t_object *new_obj);
void		add_light(t_scene *scene, t_light *new_light);

// events_handlers.c
int			events_handler(int key, t_renderer *r);
int			exit_handler(t_renderer *r);
int			mouse_handler(int button, int x, int y, t_renderer *r);

// free_utils.c
void		free_mlx(t_mlx *mlx);
void		free_scene(t_scene *scene);
void		free_data(t_data *data);
void		free_renderer(t_renderer *r);
void		free_mat(char **mat);

// error_utils.c
int			launch_error(int error, char *line1, char *line2, char *line3);
void		print_error(char *line1, char *line2, char *line3);
void		exit_error(t_renderer *r, char *l1, char *l2, char *l3);

// equation_utils.c
bool		equation_solve(t_equation *eq);

// data_init.c
void		init_data(t_data *data, char *line);
t_renderer	*init_renderer(char *line);

// mlx_init.c
void		init_mlx(t_mlx *mlx);

// file_checker_funcs.c
int			check_file(t_renderer *r);

// general_checker_funcs.c
int			detect_checker(char **line, t_renderer *r);
void		check_scene(t_renderer *r);
void		check_args(int ac, char *file);

// rendering
void		generate_rays(t_renderer *renderer);
void		calculate_up_left_and_steps(t_renderer *r);
void		fill_hit_info_ray(t_scene *scene, t_ray *ray);

// collision
bool		check_collision_circle(t_circle *circle, t_ray *ray,
				t_hit *hit_info);
void		check_collision_cone(t_object *obj, t_ray *ray, t_hit *hit_info);
void		check_collision_cylinder(t_object *obj, t_ray *ray,
				t_hit *hit_info);
void		check_collision_plane(t_object *obj, t_ray *ray, t_hit *hit_info);
void		check_collision_sphere(t_object *obj, t_ray *ray, t_hit *hit);

//
t_rgb		apply_lighting(t_scene *scene, t_hit *hit);

// color_pixel.c
void		color_pixel(t_renderer *r, t_ray *ray, int32_t x, int32_t y);

// get_object_from_pixel.c
t_object	*get_object_from_pixel(t_renderer *r, int32_t x, int32_t y);
void		change_selected_obj(t_renderer *r, int32_t x, int32_t y);

#endif
