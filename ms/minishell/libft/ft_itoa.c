/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 05:35:00 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/02 05:04:32 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_gosh(char *str, int i, int k, int n)
{
	while (i > k - 1)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	k = (n < 0 ? 1 : 0);
	str = (char*)malloc(jy_intlen(n) + k + 1);
	if (str)
	{
		if (n < 0)
		{
			str[i] = '-';
			n = -n;
		}
		i = jy_intlen(n) + k - 1;
		str = ft_gosh(str, i, k, n);
		str[++i] = '\0';
		return (str);
	}
	return (NULL);
}
