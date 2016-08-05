/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jy_btree_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:06:31 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 10:17:21 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*jy_btree_cmp(t_btree *t1, t_btree *t2)
{
	t_btree	*tek;

	tek = NULL;
	if (t1->data == t2->data && t1 && t2)
	{
		jy_btree_cmp(t1->right, t2->right);
		jy_btree_cmp(t1->left, t2->left);
	}
	if (t1->data != t2->data)
	{
		tek->left = t1;
		tek->right = t2;
		return (tek);
	}
	return (NULL);
}
