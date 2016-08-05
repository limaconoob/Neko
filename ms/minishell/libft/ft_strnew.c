/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 04:31:44 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/02 04:07:24 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	void *data;

	data = ft_memalloc(size + 1);
	if (data)
	{
		str = (char*)data;
		return (str);
	}
	else
		return (NULL);
}
