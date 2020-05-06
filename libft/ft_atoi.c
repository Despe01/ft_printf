/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:47:17 by smurad            #+#    #+#             */
/*   Updated: 2019/12/18 13:24:53 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				isneg;
	long long int	res;

	isneg = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' ||
	*str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		isneg = isneg * -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10;
		res = res + ((int)*str - 48);
		str++;
	}
	res = res * isneg;
	return (res);
}
