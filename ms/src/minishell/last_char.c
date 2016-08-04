/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 06:35:30 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/24 18:47:25 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				last_char(char *str, char c)
{
	int			i;

	if (!str)
		return (-1);
	i = ft_strlen(str);
	while (i >= 0 && str[i] != c)
		i--;
	if (!i && str[i] != c)
		return (-1);
	return (i);
}
