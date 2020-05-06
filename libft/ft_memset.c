/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:17:10 by smurad            #+#    #+#             */
/*   Updated: 2019/12/18 09:50:35 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr_s[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
