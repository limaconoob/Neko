/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 03:17:00 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 10:03:56 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*jy_btree_new(void const *content, size_t content_size)
{
	t_btree		*tree;

	tree = (t_btree*)malloc(sizeof(t_btree));
	if (tree != NULL)
	{
		if (content == NULL)
		{
			tree->data = NULL;
			tree->dsize = 0;
			tree->right = NULL;
			tree->left = NULL;
			return (tree);
		}
		else
		{
			tree->data = (void *)malloc(content_size);
			if (tree->data != NULL)
			{
				tree->data = ft_memcpy(tree->data, content, content_size);
				tree->dsize = content_size;
			}
		}
		return (tree);
	}
	return (NULL);
}
