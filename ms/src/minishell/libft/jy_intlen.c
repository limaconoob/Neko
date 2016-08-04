/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jy_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:49:55 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/02 04:56:02 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Rückkehre Wert:
** intlen rückgabt das 'n' Länge wie ein (int).
*/

size_t	jy_intlen(int n)
{
	size_t i;

	i = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
