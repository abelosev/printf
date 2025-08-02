#include "ft_printf.h"
#include "libft.h"

int ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr_count(char *s)
{
	int i;

	if (!s)
		return (ft_putstr_count("(null)"));
	i = 0;
	while(s[i])
		write(1, &s[i++], 1);
	return (ft_strlen(s));
}

int ft_putnbr_base_unsigned(unsigned long nbr, const char *base)
{
	char c;
	int base_len;
	int count;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long)base_len)
	{
		ft_putnbr_base_unsigned(nbr / (unsigned long)base_len, base);
		nbr = nbr % (unsigned long)base_len;
		count++;
	}
	c = base[nbr];
	count += ft_putchar_count(c);
	return (count);
}

int ft_putnbr_base_signed(long long nbr, const char *base)
{
	unsigned long tmp;
	int count;

	count = 0;
	if (nbr < 0)
	{
		tmp = -(unsigned long)nbr;
		count += ft_putchar_count('-');
	}
	else
		tmp = nbr;
	count += ft_putnbr_base_unsigned(tmp, base);
	return (count);
}