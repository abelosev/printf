#include "ft_printf.h"
#include "libft.h"

void	print_ptr(va_list ap, int *count)
{
	void *ptr;

	ptr = va_arg(ap, void *);
	if (!ptr)
		*count += ft_putstr_count("(nil)");
	else
	{
		*count += ft_putstr_count("0x");
		*count += ft_putnbr_base_unsigned((unsigned long)ptr, "0123456789abcdef");
	}
}

void	fmt_handling(const char *fmt, va_list ap, int *count)
{
	if (*fmt == '%')
		*count += ft_putchar_count('%');
	else if (*fmt == 'c')
		*count += ft_putchar_count((char)va_arg(ap, int));
	else if (*fmt == 's')
		*count += ft_putstr_count((char *)va_arg(ap, char *));
	else if (*fmt == 'd' || *fmt == 'i')
		*count += ft_putnbr_base_signed((long long)va_arg(ap, int), "0123456789");
	else if (*fmt == 'u')
		*count += ft_putnbr_base_unsigned((unsigned long)va_arg(ap, unsigned int),
			"0123456789");
	else if (*fmt == 'p')
		print_ptr(ap, count);
	else if (*fmt == 'x')
		*count += ft_putnbr_base_unsigned((unsigned long)va_arg(ap, unsigned int),
			"0123456789abcdef");
	else if (*fmt == 'X')
		*count += ft_putnbr_base_unsigned((unsigned long)va_arg(ap, unsigned int),
			"0123456789ABCDEF");
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int count;

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
			count += ft_putchar_count(*fmt);
		fmt++;
	}
	va_end(ap);
    return (count);
}