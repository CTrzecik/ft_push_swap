/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:51:32 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/06 17:52:54 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putunbr(unsigned int n);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);

#endif