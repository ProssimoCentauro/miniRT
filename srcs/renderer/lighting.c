#include "minirt.h"
/*
 * Checks if a point in the scene is in shadow with respect to a given light source.
 *
 * Parameters:
 * - scene: pointer to the scene containing all objects and lights.
 * - point: the 3D point to test.
 * - light: the light source to check shadow against.
 * - normal: the surface normal at the point, used to avoid self-shadowing.
 *
 * How it works:
 * 1. Creates a shadow ray starting slightly offset from the point towards the light.
 *    The small offset (EPSILON) prevents the ray from intersecting the surface it starts on.
 * 2. Computes the normalized direction of the ray from the point to the light.
 * 3. Initializes a hit record with infinite distance.
 * 4. Calculates the distance between the point and the light.
 * 5. Iterates over all objects in the scene, checking for ray-object intersections:
 *    - If an intersection is found closer than the light distance, the point is in shadow.
 * 6. Returns true if any object blocks the light (point is in shadow).
 * 7. Returns false if the point is directly illuminated (no blocking objects).
 *
 * Returns:
 * - true if the point is in shadow.
 * - false if the point is lit by the light.
 */

static bool is_in_shadow(t_scene *scene, t_vector point, t_light *light, t_vector normal)
{
    t_ray shadow_ray;
    t_hit shadow_hit;
	double	dist_to_light;
    t_object *obj;

    // Punto leggermente spostato per evitare auto-intersezioni
    shadow_ray.coord = vector_add(point, vector_scale(normal, EPSILON));
    shadow_ray.direction = vector_normalize(vector_sub(light->coord, shadow_ray.coord));

    shadow_hit.dist = INFINITY;

    dist_to_light = vector_length(vector_sub(light->coord, shadow_ray.coord));

    obj = scene->objs;
    while (obj)
    {
        if (obj->type == SPHERE)
            check_collision_sphere((t_sphere *)&obj->figure, &shadow_ray, &shadow_hit);
        else if (obj->type == PLANE)
            check_collision_plane((t_plane *)&obj->figure, &shadow_ray, &shadow_hit);
        else if (obj->type == CYLINDER)
            check_collision_cylinder((t_cylinder *)&obj->figure, &shadow_ray, &shadow_hit);
        else if (obj->type == CONE)
            check_collision_cone((t_cone *)&obj->figure, &shadow_ray, &shadow_hit);
        else
            assert(false);

        if (shadow_hit.dist < dist_to_light && shadow_hit.dist > EPSILON)
            return true;

        obj = obj->next;
    }
    return false;
}

/*
 * Calculates the final color at a point by applying ambient and point light illumination,
 * taking into account shadows cast by objects.
 *
 * Parameters:
 * - scene: the scene with objects and lights.
 * - hit: intersection information (position, normal, base color).
 *
 * How it works:
 * 1. Initializes the resulting color to black (or transparent black).
 * 2. Adds the ambient light contribution (global uniform illumination).
 * 3. For each point light in the scene:
 *    - Checks if the point is in shadow relative to this light using is_in_shadow().
 *    - If the point is not in shadow:
 *       - Calculates the light direction vector towards the point.
 *       - Computes the diffuse lighting component using the dot product between surface normal and light direction.
 *       - Adds this diffuse component to the final color, modulated by the material color and light intensity.
 * 4. Clamps the final color values to the range [0, 255] to avoid overflow.
 * 5. Returns the final color to be used for rendering.
 */

t_rgb apply_lighting(t_scene *scene, t_hit *hit)
{
    t_rgb result = {0};
    t_light *light = scene->lights;
    t_vector light_dir;
    double diff;

    // ambient light
    result.r += hit->rgb.r * scene->amb->ratio * (scene->amb->rgb.r / 255.0);
    result.g += hit->rgb.g * scene->amb->ratio * (scene->amb->rgb.g / 255.0);
    result.b += hit->rgb.b * scene->amb->ratio * (scene->amb->rgb.b / 255.0);

    while (light)
    {
        if (!is_in_shadow(scene, hit->point, light, hit->normal))
        {
            light_dir = vector_normalize(vector_sub(light->coord, hit->point));
            diff = fmax(0.0, vector_dot(hit->normal, light_dir));

            result.r += hit->rgb.r * diff * light->brightness * (light->rgb.r / 255.0);
            result.g += hit->rgb.g * diff * light->brightness * (light->rgb.g / 255.0);
            result.b += hit->rgb.b * diff * light->brightness * (light->rgb.b / 255.0);
        }
        light = light->next;
    }

    // Clamp between 0 and 255
    result.r = fmin(result.r, 255);
    result.g = fmin(result.g, 255);
    result.b = fmin(result.b, 255);

    return result;
}

