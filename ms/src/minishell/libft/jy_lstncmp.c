/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jy_lstncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 05:16:00 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/08 05:32:00 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Rückkehre Wert:
** lstncmp rückgabt 0, wenn beide Liste bis 'n' gleich sind,
** dass Nummer aus den Liste oder.
*/

size_t	jy_lstncmp(t_list *lst1, t_list *lst2, size_t n)
{
	if (n > 0 && lst1->content == lst2->content && lst1 && lst2)
		return (jy_lstncmp(lst1->next, lst2->next, n--));
	if (!lst1 && !lst2)
		return (0);
	return (n);
}
