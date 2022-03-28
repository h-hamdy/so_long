/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:39:28 by hhamdy            #+#    #+#             */
/*   Updated: 2021/11/30 13:05:30 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putint(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	else if (nbr < 0)
	{
		ft_putchar('-', len);
		ft_putint(nbr *(-1), len);
	}
	else if (nbr >= 0 && nbr < 10)
		ft_putchar(nbr + 48, len);
	else
	{
		ft_putint(nbr / 10, len);
		ft_putint(nbr % 10, len);
	}
}

static void	ft_check(va_list ap, char str, int *len)
{
	if (str == '%')
		ft_putchar('%', len);
	else if (str == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (str == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (str == 'i' || str == 'd')
		ft_putint(va_arg(ap, int), len);
	else if (str == 'u')
		ft_putunint(va_arg(ap, unsigned int), len);
	else if (str == 'x' || str == 'X')
		ft_puthexa(va_arg(ap, unsigned int), str, len);
	else if (str == 'p')
	{
		ft_putstr("0x", len);
		ft_putmem(va_arg(ap, unsigned long), 'x', len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		index;
	int		len;

	index = 0;
	len = 0;
	va_start(ap, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			ft_check(ap, str[index], &len);
		}
		else
			ft_putchar(str[index], &len);
		index++;
	}
	va_end(ap);
	return (len);
}
