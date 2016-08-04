/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 06:37:10 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/30 16:08:41 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh1.h"
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s || !len)
		return (NULL);
	if (!((str = (char *)malloc(len + 1))))
		shell_error(Malloc, "str in strsub");
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
