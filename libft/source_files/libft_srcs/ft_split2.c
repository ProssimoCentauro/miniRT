/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:26:27 by rtodaro           #+#    #+#             */
/*   Updated: 2025/05/14 17:26:44 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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

static size_t	count_words(const char *str, const char *delims)
{
	size_t	i = 0;
	size_t	count = 0;
	int		in_word = 0;

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

static size_t	word_len(const char *s, size_t index, const char *delims)
{
	size_t	len = 0;

	while (s[index] && !is_delim(s[index], delims))
	{
		len++;
		index++;
	}
	return (len);
}

static void	string_copy(char *dst, const char *src, size_t i, const char *delims)
{
	size_t	j = 0;

	while (src[i] && !is_delim(src[i], delims))
	{
		dst[j++] = src[i++];
	}
	dst[j] = '\0';
}

static size_t	go_to_next_word(const char *s, const char *delims, size_t i)
{
	while (s[i] && !is_delim(s[i], delims))
		i++;
	while (s[i] && is_delim(s[i], delims))
		i++;
	return (i);
}

char	**ft_split2(const char *s, const char *delims)
{
	char	**matrix;
	size_t	i = 0;
	size_t	j = 0;

	if (!s || !delims)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (count_words(s, delims) + 1));
	if (!matrix)
		return (NULL);
	while (s[i] && is_delim(s[i], delims))
		i++;
	while (s[i])
	{
		size_t len = word_len(s, i, delims);
		matrix[j] = (char *)malloc(len + 1);
		if (!matrix[j])
			return (NULL);  // Nota: memory leak potenziale qui
		string_copy(matrix[j++], s, i, delims);
		i = go_to_next_word(s, delims, i);
	}
	matrix[j] = NULL;
	return (matrix);
}

