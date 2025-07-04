/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:18:28 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/04 15:37:20 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static inline float normalize(float a)
{
    if (a > 1)
        return (1.0f);
    else if (a < 0)
        assert (false);
    return (a);
}

t_color convert_rgb(t_rgb rgb)
{
    t_color color;

    color.r = rgb.r / 255.0f;
    color.g = rgb.g / 255.0f;
    color.b = rgb.b / 255.0f;
    return (color);
}

t_rgb convert_color(t_color color)
{
    t_rgb a;

    a.r = (unsigned int)(normalize(color.r) * 255);
    a.g = (unsigned int)(normalize(color.g) * 255);
    a.b = (unsigned int)(normalize(color.b) * 255);
    a.t = 0;
    return (a);
}

t_color multiply_color(t_color a, t_color b)
{
    t_color res;

    res.r = a.r * b.r;
    res.g = a.g * b.g;
    res.b = a.b * b.b;
    return (res);
}

t_color multiply_color_scalar(t_color a, float b)
{
    t_color res;

    res.r = a.r * b;
    res.g = a.g * b;
    res.b = a.b * b;
    return (res);  
}

t_color add_color(t_color a, t_color b)
{
    t_color res;

    res.r = a.r + b.r;
    res.g = a.g + b.g;
    res.b = a.b + b.b;
    return (res);
}

t_color mean_color(t_color a, int i, t_color b)
{
    a = multiply_color_scalar(a, i);
    a = add_color(a, b);
    return (multiply_color_scalar(a, 1.0f / (i + 1)));
}