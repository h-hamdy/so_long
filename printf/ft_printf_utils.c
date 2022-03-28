/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:43:09 by hhamdy            #+#    #+#             */
/*   Updated: 2021/11/30 13:06:02 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len = *len + 1;
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_putunint(unsigned int nbr, int *len)
{
	if (nbr < 10)
		ft_putchar(nbr + 48, len);
	else if (nbr > 9)
	{
		ft_putunint(nbr / 10, len);
		ft_putunint(nbr % 10, len);
	}
}

void	ft_puthexa(unsigned int nbr, char x, int *len)
{
	char	*hex;

	hex = NULL;
	if (x == 'x')
		hex = "0123456789abcdef";
	else if (x == 'X')
		hex = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(hex[nbr % 16], len);
	if (nbr >= 16)
	{
		ft_puthexa(nbr / 16, x, len);
		ft_putchar(hex[nbr % 16], len);
	}
}

void	ft_putmem(unsigned long nbr, char x, int *len)
{
	char	*hex;

	hex = NULL;
	if (x == 'x')
		hex = "0123456789abcdef";
	else if (x == 'X')
		hex = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(hex[nbr % 16], len);
	if (nbr >= 16)
	{
		ft_putmem(nbr / 16, x, len);
		ft_putchar(hex[nbr % 16], len);
	}
}
