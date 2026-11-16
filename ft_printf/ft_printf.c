/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:03:00 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/13 17:56:13 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	print_type(const char *input, va_list *args, size_t len)
{
	if (input[1] == '%')
		return (len += ft_putchar('%'));
	if (input[1] == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (input[1] == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (input[1] == 'd' || input[1] == 'i')
		len += ft_putnbr(va_arg(*args, int));
	else if (input[1] == 'u')
		len += ft_putunbr(va_arg(*args, unsigned int));
	else if (input[1] == 'x' || input[1] == 'X'
		|| input[1] == 'p')
	{
		if (input[1] == 'X')
			len += ft_putnbr_base(va_arg(*args, unsigned int),
					"0123456789ABCDEF");
		else if (input[1] == 'p')
			len += ft_putptr(va_arg(*args, void *));
		else
			len += ft_putnbr_base(va_arg(*args, unsigned int),
					"0123456789abcdef");
	}
	else
		len += (ft_putchar(input[0]) + ft_putchar(input[1]));
	return (len);
}

static	size_t	ft_loop(const char *input, va_list *args)
{
	size_t	i;
	size_t	len;
	size_t	save_len;

	len = 0;
	i = 0;
	save_len = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] != '\0')
			len = print_type(input + i++, args, len);
		else
			len += ft_putchar(input[i]);
		if (len == save_len - 1)
			return (-1);
		save_len = len;
		i++;
	}
	return (len);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	len;

	if (!input)
		return (-1);
	len = 0;
	va_start(args, input);
	len = ft_loop(input, &args);
	va_end(args);
	return (len);
}
