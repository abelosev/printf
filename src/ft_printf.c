/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:03:46 by anbelose          #+#    #+#             */
/*   Updated: 2025/08/02 20:16:23 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	print_ptr(va_list ap, int *count)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	if (!ptr)
		*count += putstr_c("(nil)");
	else
	{
		*count += putstr_c("0x");
		*count += putnbr_u((uintptr_t)ptr,
				"0123456789abcdef");
	}
}

void	fmt_handling(const char *fmt, va_list ap, int *count)
{
	if (*fmt == '%')
		*count += putchar_c('%');
	else if (*fmt == 'c')
		*count += putchar_c((char)va_arg(ap, int));
	else if (*fmt == 's')
		*count += putstr_c((char *)va_arg(ap, char *));
	else if (*fmt == 'd' || *fmt == 'i')
		*count += putnbr_s((long long)va_arg(ap, int), "0123456789");
	else if (*fmt == 'u')
		*count += putnbr_u((unsigned long)va_arg(ap, unsigned int),
				"0123456789");
	else if (*fmt == 'p')
		print_ptr(ap, count);
	else if (*fmt == 'x')
		*count += putnbr_u((unsigned long)va_arg(ap, unsigned int),
				"0123456789abcdef");
	else if (*fmt == 'X')
		*count += putnbr_u((unsigned long)va_arg(ap, unsigned int),
				"0123456789ABCDEF");
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	if (!fmt)
		return (0);
	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt++;
			fmt_handling(fmt, ap, &count);
		}
		else
			count += putchar_c(*fmt);
		fmt++;
	}
	va_end(ap);
	return (count);
}
