#include "../ft_printf.h"

static char		*zero_init(t_flags *flags)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(res = (char *)malloc(sizeof(char) * (flags->prec + 1))))
		return (NULL);
	while (i < flags->prec)
		res[i++] = '0';
	res[i] = '\0';
	if (flags->type_ret[0] == '-')
	{
		tmp = ft_strjoin(res, flags->type_ret + 1);
		free(res);
		res = ft_strjoin("-", tmp);
	}
	else
	{
		tmp = ft_strjoin(res, flags->type_ret);
		free(res);
		res = ft_strdup(tmp);
	}
	free(tmp);
	return (res);
}

static size_t	ftpreclen(const char *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] != '-')
			{
				j++;
			}
			i++;
		}
	}
	return (j);
}

char			*ft_joinprec(t_flags *flags)
{
	char	*res;
	int		i;

	res = ft_strdup("");
	i = 0;
	if (flags->prec >= 0 && flags->type == 1)
		flags->zero_width_disable = 1;
	if (flags->type == 0 && flags->prec >= 0)
		while ((flags->prec-- > 0) && flags->type_ret[i])
			res = ft_append_char(res, flags->type_ret[i++]);
	else if (flags->type == 1 && flags->prec > 0 &&
	(flags->prec > (int)ftpreclen(flags->type_ret)))
	{
		flags->prec = flags->prec - ftpreclen(flags->type_ret);
		free(res);
		res = zero_init(flags);
	}
	else if (((flags->type_ret[0] == '0' && flags->type_ret[1] == 0)
	&& flags->type == 1 && flags->prec == 0))
		return (res);
	else
	{
		free(res);
		return (ft_strdup(flags->type_ret));
	}
	return (res);
}
