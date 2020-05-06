/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 07:54:33 by smurad            #+#    #+#             */
/*   Updated: 2019/12/18 13:28:59 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int				iend;
	char			*res;
	unsigned int	i;

	res = NULL;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	iend = ft_strlen(s1) - 1;
	while (s1[i] && isset(s1[i], set))
	{
		i++;
		iend--;
	}
	if (iend >= 0)
	{
		while (isset(s1[iend + i], set))
			iend--;
	}
	res = malloc(sizeof(char) * iend + 1);
	if (res == NULL)
		return (res);
	res = ft_substr(s1, i, iend + 1);
	return (res);
}
