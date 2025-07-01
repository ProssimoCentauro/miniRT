/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:15:29 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/01 18:23:32 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	printf_ft_putstr(char *str)
{
	ssize_t	len;

	if (!str)
		return (printf_ft_putstr(FT_NULL_STR));
	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return (write(STDOUT_FILENO, str, len));
}

int	printf_ft_putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		printf_ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		printf_ft_putchar('-');
		count++;
	}
	if (n >= 10)
		count = printf_ft_putnbr(n / 10, count);
	printf_ft_putchar((n % 10) + '0');
	count++;
	return (count);
}
