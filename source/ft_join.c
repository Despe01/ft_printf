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

char *ft_joinprec(FlagStruct *flags, int *count)
{
  //int len;
  char *res;
  //int i;

  //i = 0;
  res = ft_strdup("");
  if (flags->type == 0)
  {
    //len = ftstrlen(flags->type_ret);
    printf("%c\n", *flags->type_ret);
    while((flags->prec > 0) && *flags->type_ret)
    {
      res = ft_append_char(res, *flags->type_ret);
      flags->type_ret++;
      flags->prec--;
      *count = *count + 1;
    }
    return (res);
  }
  else if (flags->type == 1)
  {

  }
  return res;
}

void ft_join(FlagStruct *flags, int *count)
{
  char *res;

  res = NULL;
  printf("%d\n", *count);
  if (flags->flag == 1)
  {
    res = ft_joinprec(flags, count);
    printstruct(flags);
    ft_putstr_fd(res, 1);
  }
}
