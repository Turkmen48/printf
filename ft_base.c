/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhadurm <panterreyiz48@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:33:05 by muhadurm          #+#    #+#             */
/*   Updated: 2023/11/06 19:51:04 by muhadurm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_mystr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (*str)
	{
		if (write(1, &*str, 1) == -1)
			return (-1);
		i++;
		str++;
	}
	return (i);
}

int	ft_mychar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_pointer(unsigned long int p)
{
	int	esc;
	int	temp;

	esc = 0;
	if (p < 16)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		esc += 2;
	}
	if (p >= 16)
	{
		temp = ft_pointer(p / 16);
		if (temp == -1)
			return (-1);
		esc += temp;
	}
	if (write(1, &"0123456789abcdef"[p % 16], 1) == -1)
		return (-1);
	return (++esc);
}

int	ft_pointerx(unsigned int x)
{
	int	esc;
	int	temp;

	esc = 0;
	if (x >= 16)
	{
		temp = ft_pointerx(x / 16);
		if (temp == -1)
			return (-1);
		esc += temp;
	}
	if (write(1, &"0123456789abcdef"[x % 16], 1) == -1)
		return (-1);
	return (++esc);
}

int	ft_pointerbigx(unsigned int x)
{
	int	esc;
	int	temp;

	esc = 0;
	if (x >= 16)
	{
		temp = ft_pointerbigx(x / 16);
		if (temp == -1)
			return (-1);
		esc += temp;
	}
	if (write(1, &"0123456789ABCDEF"[x % 16], 1) == -1)
		return (-1);
	return (++esc);
}
