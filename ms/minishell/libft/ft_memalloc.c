/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 02:50:13 by jpepin            #+#    #+#             */
/*   Updated: 2015/11/26 07:29:04 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *data;

	data = (void *)malloc(size);
	if (data)
	{
		ft_bzero(data, size);
		return (data);
	}
	else
		return (NULL);
}
