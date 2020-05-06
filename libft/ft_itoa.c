/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:52:56 by smurad            #+#    #+#             */
/*   Updated: 2019/12/18 18:47:51 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*strswap(char *s)
{
	char	*res;
	int		len;
	int		i;

	len = (ft_strlen(s) - 1);
	i = 0;
	res = NULL;
	res = malloc(sizeof(char) * (len + 2));
	if (res == NULL)
		return (res);
	while (s[i] != '\0')
	{
		res[i] = s[len - i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char				*checkzero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static long long int	checkneg(int n)
{
	long long int	n_long;

	n_long = (long long int)n;
	if (n_long < 0)
		return (n_long * -1);
	else if (n_long > 0)
		return (n_long);
	return (0);
}

static int				checklen(int n)
{
	int				len;
	long long int	n_long;

	n_long = (long long int)n;
	len = 1;
	if (n_long < 0)
	{
		n_long = n_long * -1;
		len++;
	}
	while (n_long >= 10)
	{
		n_long = n_long / 10;
		len++;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	char			*res;
	int				i;
	long long int	j;
	int				neg;

	i = 0;
	j = 0;
	neg = 0;
	if (!(res = malloc(sizeof(char) * checklen(n) + 1)))
		return (NULL);
	if (n == 0)
		return (checkzero(res));
	else if (n < 0)
		neg = 1;
	j = checkneg(n);
	while (j != 0)
	{
		res[i++] = (j % 10) + '0';
		j = j / 10;
	}
	if (neg)
		res[i++] = '-';
	res[i] = '\0';
	res = strswap(res);
	return (res);
}
