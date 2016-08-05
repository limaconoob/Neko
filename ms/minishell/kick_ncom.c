/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick_ncom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:19:17 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 07:42:19 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdlib.h>

t_ncom			*kick_ncom(t_ncom **ncom)
{
	t_ncom		*tmp;

	if (ncom && *ncom)
	{
		tmp = (*ncom)->next;
		ftab((*ncom)->av);
		free(*ncom);
		*ncom = tmp;
	}
	return (*ncom);
}
