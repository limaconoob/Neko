/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 04:03:55 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 08:32:28 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	t_list	*tmp;

	if (*alst != NULL && del != NULL)
	{
		list = *alst;
		while (list)
		{
			if (list->next)
				tmp = list->next;
			else
				tmp = NULL;
			del(list->content, list->content_size);
			free(list);
			list = tmp;
		}
		*alst = NULL;
	}
}
