/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jy_btree_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 08:56:33 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 09:56:17 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		jy_btree_check(t_btree *tree, void *content)
{
	while (tree != NULL)
	{
		if (tree->data < content)
			tree = tree->right;
		else if (tree->data > content)
			tree = tree->left;
		else
			return (1);
	}
	return (0);
}
