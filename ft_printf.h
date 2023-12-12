/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhadurm <panterreyiz48@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:14:05 by muhadurm          #+#    #+#             */
/*   Updated: 2023/11/06 15:40:50 by muhadurm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	ft_unsigned(unsigned int un);
int	ft_pointer(unsigned long int p);
int	ft_pointerx(unsigned int x);
int	ft_pointerbigx(unsigned int x);
int	ft_mystr(char *str);
int	ft_decimal(int x);
int	ft_mychar(int c);
#endif
