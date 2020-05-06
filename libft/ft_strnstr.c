/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 05:49:26 by smurad            #+#    #+#             */
/*   Updated: 2019/12/18 10:24:55 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkstr(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	while (needle[i])
	{
		if (haystack[i] == needle[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	lenneedle;

	lenneedle = ft_strlen(needle);
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0] && (lenneedle + i) <= len &&
		checkstr((&haystack[i]), needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
