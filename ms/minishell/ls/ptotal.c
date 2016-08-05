/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptotal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 05:02:50 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 22:04:41 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <stdlib.h>

void				ptotal(int total)
{
	char			*gtoto;
	char			*totoa;

	totoa = ft_itoa(total);
	gtoto = ft_strjoin("total ", totoa);
	write(1, gtoto, ft_strlen(gtoto));
	write(1, "\n", 1);
	free(gtoto);
	free(totoa);
}
