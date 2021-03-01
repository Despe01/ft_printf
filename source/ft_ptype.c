/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:05:15 by smurad            #+#    #+#             */
/*   Updated: 2021/03/01 06:22:53 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long	checklen(unsigned long long n, unsigned int base)
{
	long	len;

	len = 1;
	while (n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static char	*ft_itoa_base_ull(unsigned long long n, unsigned int base,
	char *digits)
{
	long	i;
	char	*res;

	i = checklen(n, base);
	if (!(res = malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while (n >= base)
	{
		res[--i] = digits[n % base];
		n = n / base;
	}
	res[--i] = digits[n];
	return (res);
}

char		*ft_ptype(va_list param, t_flags *flags)
{
	long long	ptr;
	char		*str;
	char		*tmp;

	str = NULL;
	tmp = NULL;
	ptr = (long long)va_arg(param, long long);
	flags->type = 0;
	if (ptr == 0 && flags->prec_dot == 1)
	{
		return (ft_strdup("0x"));
	}
	else if (ptr < 0)
	{
		tmp = ft_itoa_base_ull((unsigned long long)ptr, 16, "0123456789abcdef");
		str = ft_strjoin("0x", tmp);
	}
	else
	{
		tmp = ft_itoa_base(ptr, 16, "0123456789abcdef");
		str = ft_strjoin("0x", tmp);
	}
	free(tmp);
	return (str);
}
