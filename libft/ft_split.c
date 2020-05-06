/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:20:39 by smurad            #+#    #+#             */
/*   Updated: 2019/12/18 08:04:53 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	strcount(char const *s, char c)
{
	int	i;
	int	j;
	int	scount;

	scount = 0;
	j = 0;
	i = 0;
	while (s[j])
	{
		while (s[j] == c && s[j])
		{
			i = 0;
			j++;
		}
		while (s[j] != c && s[j])
		{
			i++;
			j++;
		}
		if (i != 0)
			scount++;
	}
	return (scount);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		istart;
	int		ilen;
	int		i;

	i = 0;
	ilen = 0;
	istart = 0;
	if (!s || !(res = malloc(sizeof(char *) * (strcount(s, c) + 1))))
		return (NULL);
	while (s[istart])
	{
		while (s[istart] == c && s[istart + ilen])
			istart++;
		while (s[istart + ilen] != c && s[istart + ilen])
			ilen++;
		if (ilen != 0)
		{
			res[i++] = ft_substr(s, istart, ilen);
			istart = istart + ilen;
			ilen = 0;
		}
	}
	res[i] = NULL;
	return (res);
}
