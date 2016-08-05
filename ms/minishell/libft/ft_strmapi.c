/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 04:55:02 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/02 04:11:08 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		str = (char *)malloc(ft_strlen(s) + 1);
		if (str)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
		}
		else
			str = NULL;
		return (str);
	}
	else
		return (NULL);
}
