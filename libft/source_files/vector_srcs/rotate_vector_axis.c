#include "vector.h"


t_vector	rotate_vector_axis(t_vector v, t_vector axis, double angle)
{
	t_vector	res;
	double		cos_t;
	double		sin_t;

	cos_t = cos(angle);
	sin_t = sin(angle);
	axis = vector_normalize(axis);
	res = vector_add(vector_scale(v, cos_t),
			vector_add(vector_scale(vector_cross(axis, v), sin_t),
				vector_scale(axis, vector_dot(axis, v) * (1 - cos_t))));
	return (res);
}
