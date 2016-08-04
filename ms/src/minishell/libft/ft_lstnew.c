/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 03:17:00 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 09:25:32 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list != NULL)
	{
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
			list->next = NULL;
			return (list);
		}
		else
		{
			list->content = (void*)malloc(content_size);
			if (list->content != NULL)
			{
				list->content = ft_memcpy(list->content, content, content_size);
				list->content_size = content_size;
			}
		}
		return (list);
	}
	return (NULL);
}
