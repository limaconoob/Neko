/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jy_btree_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 03:57:47 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 10:08:01 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	jy_btree_add(t_btree **abtr, t_btree *new)
{
	t_btree	*tek;

	if (*abtr != NULL && *abtr)
	{
		tek = *abtr;
		if (tek->data >= new->data)
			new->right = *abtr;
		else
			new->left = *abtr;
		*abtr = new;
	}
	else
		*abtr = new;
}
