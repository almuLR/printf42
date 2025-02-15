/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almlopez <almlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:51:02 by almlopez          #+#    #+#             */
/*   Updated: 2025/02/15 15:44:40 by almlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
# define H_LOW "0123456789abcdef"
# define H_UP "0123456789ABCDEF"
# define UNSIG_INT "0123456789"

int	what_letter(char *str, int *i, va_list args)
{
	int count;

	count = 0;
	if (str[*i] == '%' && str[*i + 1])
	{
		(*i)++;
		if (str[*i] == 'c')
			return (ft_putchar_fd((unsigned char)va_arg(args, int),
			1));
		else if (str[*i] == 's')
			return (ft_putstr_fd(va_arg(args, char *), 1));
		else if (str[*i] == 'p')
			return (ft_putptr(va_arg(args, void *), 1));
		else if (str[*i] == 'd')
			return (ft_putnbr_fd(va_arg(args, int), 1));
		else if (str[*i] == 'i')
			return (ft_putnbr_fd(va_arg(args, int), 1));
		else if (str[*i] == 'u')
			return (ft_putnbr_unsigned(va_arg(args, unsigned int),
			UNSIG_INT));
		else if (str[*i] == 'x')
			return (ft_putnbr_base(va_arg(args, int), H_LOW));
		else if (str[*i] == 'X')
			return (ft_putnbr_base(va_arg(args, int), H_UP));
		else if (str[*i] == '%')
			return (ft_putchar_fd('%', 1));
		
	}
	else if (str[*i] != '%')
		return (ft_putchar_fd(str[*i], 1));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int	i;
	int	count;
	va_list	args;

	if (!str)
		return(-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		count += what_letter((char *)str, &i, args);
		i++;
	}
	va_end(args);
	return (count);
}

//tiene que devolver NIL no NULL
/*#include <stdio.h>
int main ()
{
	ft_printf("%c", '0');
	ft_printf("%s", "holaholahola");
	ft_printf("%i", 12345);
	printf("%c", 'a');
	printf("%s", "holaholahola");
	printf("%i", 12345);
	return (0);
}*/