/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:15:06 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 08:23:26 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*tmp;

	if (lst != NULL && f != NULL)
	{
		map = (*f)(ft_lstnew(lst->content, lst->content_size));
		if (map != NULL)
		{
			tmp = map;
			while (lst->next && tmp != NULL)
			{
				lst = lst->next;
				tmp->next = (*f)(ft_lstnew(lst->content, lst->content_size));
				tmp = tmp->next;
			}
			return (map);
		}
	}
	return (NULL);
}
