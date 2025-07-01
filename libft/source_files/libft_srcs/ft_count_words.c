/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:16:24 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/01 10:20:44 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delim(char c, const char *delims)
{
	while (*delims)
	{
		if (c == *delims)
			return (1);
		delims++;
	}
	return (0);
}

size_t	ft_count_words(const char *str, const char *delims)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_delim(str[i], delims) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_delim(str[i], delims))
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}
