/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:50:06 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/27 11:21:10 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  The 'tem' variable is used for not ignoring the result value of 'write',
 *  which would cause a warning if compiled with an optimization flag.
 *  This introduces a small overhead when compiled without optimizations
 *  but allows the compiler to not complain with the optimization flag.
 *  If the optimization flag is set, the instruction generated
 *  ignores the 'tem' variable and doesn't even make space
 *  for it in the stack, making the code as if 'tem' was not declared.
 *
 *  More elegant solutions for not introducing even the little overhead
 *  in case it was not running with the optimization are:
 *
 *  1) Using the `register` keyword:
 *     register ssize_t tem = write(fd, s, ft_strlen(s));
 *     (void)tem;
 *
 *     Using the register keyword could not work for some compilers and
 *     in general is good practice to avoid since it is deprecated, but
 *     in this case suggests the compiler to use a register to store
 *     the write result. Probably, the register used will be the same as
 *     the one used for the return value, generating the same instruction
 *     as the normal version. This solution is not suggested.
 *
 *  2) Ignoring the warning:
 *     Using a compiler flag to ignore the warning globally (while compiling)
 *     with the flag "-Wunused-result"
 *     Or locally (GCC/Clang-specific):
 *     #pragma GCC diagnostic push
 *     #pragma GCC diagnostic ignored "-Wunused-result"
 *       write(fd, s, ft_strlen(s));
 *     #pragma GCC diagnostic pop
 *
 *     However, for the purposes of this exercise and the restriction against
 *     preprocessor directives, we choose the simpler approach.
 */

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	tem;

	if (!s)
		return ;
	tem = write(fd, s, ft_strlen(s));
	(void)tem;
}