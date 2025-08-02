#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *fmt, ...);
int ft_putnbr_base_unsigned(unsigned long nbr, const char *base);
int ft_putnbr_base_signed(long long nbr, const char *base);
int ft_putstr_count(char *s);
int ft_putchar_count(char c);

#endif