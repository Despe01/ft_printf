/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:37:54 by smurad            #+#    #+#             */
/*   Updated: 2021/02/28 04:38:56 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_append_char(char *str, char chr)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (!(ret = (char *)malloc(sizeof(char) * (ftstrlen(str) + 2))))
		return (NULL);
	if (str != NULL)
	{
		while (str[i])
		{
			ret[i] = str[i];
			i++;
		}
	}
	ret[i] = chr;
	ret[i + 1] = '\0';
	free(str);
	return (ret);
}
