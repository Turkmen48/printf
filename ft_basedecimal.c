/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basedecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhadurm <panterreyiz48@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:03:20 by muhadurm          #+#    #+#             */
/*   Updated: 2023/11/06 19:50:29 by muhadurm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_decimal(int x)
{
	int				esc;
	unsigned int	number;
	int				temp;

	esc = 0;
	if (x < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		++esc;
		number = -x;
	}
	else
		number = x;
	if (number >= 10)
	{
		temp = ft_decimal(number / 10);
		if (temp == -1)
			return (-1);
		esc += temp;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (++esc);
}

int	ft_unsigned(unsigned int un)
{
	int	esc;
	int	temp;

	esc = 0;
	if (un >= 10)
	{
		temp = ft_unsigned(un / 10);
		if (temp == -1)
			return (-1);
		esc += temp;
	}
	if (write(1, &"0123456789"[un % 10], 1) == -1)
		return (-1);
	return (++esc);
}
