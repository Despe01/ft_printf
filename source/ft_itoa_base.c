/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:44:23 by smurad            #+#    #+#             */
/*   Updated: 2020/03/04 21:34:10 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	checklen(int n, int base)
{
	int	len;

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

char		*ft_itoa_base(int n, int base, char *digits)
{
	int		i;
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
