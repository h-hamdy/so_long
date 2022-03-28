/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:41:06 by hhamdy            #+#    #+#             */
/*   Updated: 2021/11/29 08:09:04 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char str, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putunint(unsigned int nbr, int *len);
void	ft_puthexa(unsigned int nbr, char x, int *len);
void	ft_putmem(unsigned long nbr, char x, int *len);

#endif
