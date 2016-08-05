/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putescstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:24:43 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/06 07:49:11 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void	ft_putescstr(char const *s)
{
	while (*s)
	{
		if (!ft_isspace(*s) && *s != '\n')
			ft_putchar(*s);
		else if (*s == '\n')
			ft_putstr("\\n");
		else if (*s == '\t')
			ft_putstr("\\t");
		else if (*s == '\v')
			ft_putstr("\\v");
		else if (*s == '\r')
			ft_putstr("\\r");
		else if (*s == '\f')
			ft_putstr("\\f");
		else
			ft_putchar(' ');
		s++;
	}
	ft_putchar('\n');
}
