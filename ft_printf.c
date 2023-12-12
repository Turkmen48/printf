/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhadurm <panterreyiz48@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:28:25 by muhadurm          #+#    #+#             */
/*   Updated: 2023/11/06 15:41:15 by muhadurm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_format(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_mychar(va_arg(args, int)));
	else if (flag == 's')
		return (ft_mystr(va_arg(args, char *)));
	else if (flag == 'd' || flag == 'i')
		return (ft_decimal(va_arg(args, int)));
	else if (flag == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (flag == 'p')
		return (ft_pointer(va_arg(args, unsigned long int)));
	else if (flag == 'x')
		return (ft_pointerx(va_arg(args, unsigned int)));
	else if (flag == 'X')
		return (ft_pointerbigx(va_arg(args, unsigned int)));
	else if (flag == '%')
		return (ft_mychar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		temp;
	va_list	args;
	int		control;

	va_start(args, str);
	temp = 0;
	while (*str)
	{
		if (*str == '%')
		{
			control = ft_format(*(++str), args);
			if (control == -1)
				return (-1);
			temp += control;
			str++;
		}
		else
		{
			if (write(1, &(*str), 1) == -1)
				return (-1);
			str++;
			temp++;
		}
	}
	return (va_end(args), temp);
}
