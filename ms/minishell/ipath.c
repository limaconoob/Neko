/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipath.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:20:32 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/18 06:54:58 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdlib.h>

t_path			*ipath(char *name)
{
	t_path		*stock;

	if (!((stock = (t_path*)malloc(sizeof(t_path)))))
		shell_error(Malloc, "stock in ielem");
	stock->path_name = name;
	stock->permission = 0;
	stock->next = NULL;
	return (stock);
}
