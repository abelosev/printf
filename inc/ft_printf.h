/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:03:14 by anbelose          #+#    #+#             */
/*   Updated: 2025/08/02 20:03:33 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *fmt, ...);
int	putnbr_u(unsigned long long nbr, const char *base);
int	putnbr_s(long long nbr, const char *base);
int	putstr_c(char *s);
int	putchar_c(char c);

#endif
