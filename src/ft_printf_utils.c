/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:16:48 by anbelose          #+#    #+#             */
/*   Updated: 2025/08/02 20:18:57 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	putchar_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr_c(char *s)
{
	int	i;

	if (!s)
		return (putstr_c("(null)"));
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	putnbr_u(unsigned long long nbr, const char *base)
{
	char	c;
	int		base_len;
	int		count;

	count = 0;
	base_len = (int)ft_strlen(base);
	if (nbr >= (unsigned long long)base_len)
	{
		putnbr_u(nbr / (unsigned long)base_len, base);
		nbr = nbr % (unsigned long)base_len;
		count++;
	}
	c = base[nbr];
	count += putchar_c(c);
	return (count);
}

int	putnbr_s(long long nbr, const char *base)
{
	unsigned long long	tmp;
	int				count;

	count = 0;
	if (nbr < 0)
	{
		tmp = (unsigned long long)(-nbr);
		count += putchar_c('-');
	}
	else
		tmp = (unsigned long long)nbr;
	count += putnbr_u(tmp, base);
	return (count);
}
