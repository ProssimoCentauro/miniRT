#include "minirt.h"

int is_valid_integer(char *str)
{
    int i = 0;
    int has_digit = 0;

    if (str[0] == '\0')
        return (1);
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] != '\0')
	{
        if (ft_isdigit(str[i]))
            has_digit = 1;
		else
            return (1);
        i++;
    }
    if (!has_digit)
        return (1);
    return (0);
}

static int is_double_format_valid(const char *str)
{
    int i = 0;
    int dot_count = 0;
    int has_digit = 0;

    if (str[0] == '\0')
        return (0);
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]))
            has_digit = 1;
        else if (str[i] == '.')
        {
            dot_count++;
            if (dot_count > 1)
                return (0);
        }
        else
            return (0);
        i++;
    }
    return (has_digit);
}

int is_valid_double(char *str, double *num)
{
    if (!is_double_format_valid(str))
        return (1);
    if (num)
        *num = ft_atod(str);
    return (0);
}

int is_valid_vector_range(char* str)
{
	double	res;

	if (is_valid_double(str, NULL))
		return (1);
	res = ft_atod(str);
	if (res < -1.0 || res > 1.0)
		return (1);
	return (0);
}
