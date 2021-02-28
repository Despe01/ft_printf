/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:44:23 by smurad            #+#    #+#             */
/*   Updated: 2021/02/28 04:38:19 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long int	checklen(long n, int base)
{
	long int len;

	len = 1;
	if (n < 0)
		len++;
	while (n <= (base * -1) || n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(long n, int base, char *digits)
{
	long	i;
	char	*res;

	i = checklen(n, base);
	if (!(res = malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while (n <= (base * -1) || n >= base)
	{
		res[--i] = (n >= 0) ? digits[n % base] : digits[((n % base) * -1)];
		n = n / base;
	}
	if (n < 0)
		res[0] = '-';
	res[--i] = (n >= 0) ? digits[n] : digits[(n * -1)];
	return (res);
}
