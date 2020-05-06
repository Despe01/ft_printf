/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:44:19 by smurad            #+#    #+#             */
/*   Updated: 2020/03/05 00:06:54 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char *zero_init(FlagStruct *flags)
{
  char *res;
  char *tmp;
  int i;

  i = 0;
  tmp = NULL;
  if (!(res = (char *)malloc(sizeof(char) * (flags->prec + 1))))
    return (NULL);
  while (i < flags->prec)
  {
    res[i] = '0';
    i++;
  }
  res[i] = '\0';
  if (flags->type_ret[0] == '-')
  {
    tmp = ft_strjoin(res, flags->type_ret + 1);
    free(res);
    res = ft_strjoin("-", tmp);
    free(tmp);
  }
  else
  {
    tmp = ft_strjoin(res, flags->type_ret);
    free(res);
    res = ft_strdup(tmp);
    free(tmp);
  }
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

char *ft_joinprec(FlagStruct *flags)
{
  char *res;
  int i = 0;

  res = ft_strdup("");
  if (flags->prec >= 0 && flags->type == 1)
  {
    flags->zero_width_disable = 1;
  }
  if (flags->type == 0 && flags->prec >= 0)
  {
    while((flags->prec-- > 0) && flags->type_ret[i])
    {
      res = ft_append_char(res, flags->type_ret[i++]);
      //flags->type_ret++;
      //flags->prec--;
    }
  }
  else if (flags->type == 1 && flags->prec > 0 &&
    (flags->prec > (int)ftpreclen(flags->type_ret)))
  {
    flags->prec = flags->prec - ftpreclen(flags->type_ret);
    free(res);
    res = zero_init(flags);
    //flags->zero_width_disable = 1;
    /*if (flags->prec > (int)ftstrlen(flags->type_ret))
    {
      flags->prec = flags->prec - ftstrlen(flags->type_ret);
      res = zero_init(flags);
    }
    else
      return (flags->type_ret);*/
  }
  else if (((flags->type_ret[0] == '0' && flags->type_ret[1] == 0) && flags->type == 1
  && flags->prec == 0))
    return res;
  else
  {
    free(res);
    return (ft_strdup(flags->type_ret));
  }
  return res;
}

static char *width_init(int i, char c)
{
  char *res;

  res = NULL;
  if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
    return (NULL);
  res[i] = '\0';
  while (i > 0)
  {
    i--;
    res[i] = c;
  }
  return res;
}

char *ft_joinwidth(FlagStruct *flags, char *s)
{
  int len;

  /*if (flags->type == 1)
    len = ftpreclen(s);
  else*/
    len = ftstrlen(s) + flags->czero;
  if(flags->width > len)
  {
    len = flags->width - len;
    if(flags->zero_width == 0 || flags->zero_width_disable == 1)
    {
      return width_init(len, ' ');
    }
    else if(flags->zero_width == 1)
      return width_init(len, '0');
  }
  return ft_strdup("");
}

void ft_join(FlagStruct *flags, int *count)
{
  char *prec;
  char *width;
  char *res;
  char *tmp;

  prec = ft_joinprec(flags);
  width = ft_joinwidth(flags, prec);
  res = NULL;
  tmp = NULL;
  if (flags->flag == 1)
  {
    res = ft_strjoin(prec, width);
    *count = *count + (int)ftstrlen(res) + flags->czero;
    //res = ft_joinprec(flags);
    if (flags->czero == 1)
    {
      ft_putchar_fd(0, 1);
      ft_putstr_fd(width, 1);
    }
    else
      ft_putstr_fd(res, 1);
  }
  else
  {
    if (width[0] == '0' && flags->type_ret[0] == '-')
    {
      tmp = ft_strjoin(width, prec + 1);
      res = ft_strjoin("-", tmp);
      //free(tmp);
    }
    else
      res = ft_strjoin(width, prec);
    *count = *count + (int)ftstrlen(res) + flags->czero;
    if (flags->czero == 1)
    {
      ft_putstr_fd(width, 1);
      ft_putchar_fd(0, 1);
    }
    else
      ft_putstr_fd(res, 1);
  }
  free(prec);
  free(width);
  free(res);
  free(tmp);
}
