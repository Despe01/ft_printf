/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:50:51 by smurad            #+#    #+#             */
/*   Updated: 2019/12/18 09:23:57 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && i <= ft_strlen(s1) && i <= ft_strlen(s2))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			if (((unsigned char)s1[i] - (unsigned char)s2[i]) < 0)
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
