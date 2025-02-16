/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almudenalopezrodriguez <almudenalopezro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:51:02 by almlopez          #+#    #+#             */
/*   Updated: 2025/02/16 16:30:54 by almudenalop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#define H_LOW "0123456789abcdef"
#define H_UP "0123456789ABCDEF"
#define UNSIG_INT "0123456789"

int	do_operations(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd((unsigned char)va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *), 1));
	else if (c == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int),
				UNSIG_INT));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), H_LOW));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), H_UP));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	search_letter(char *str, int *i, va_list args)
{
	if (str[*i] == '%' && str[*i + 1])
		return (do_operations(str[++(*i)], args));
	return (ft_putchar_fd(str[*i], 1));
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		count += search_letter((char *)str, &i, args);
		i++;
	}
	va_end(args);
	return (count);
}
