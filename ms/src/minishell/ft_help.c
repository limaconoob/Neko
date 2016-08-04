/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 19:38:35 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/18 07:45:30 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void			ft_help(char **av, char *exec_path)
{
	if (tab_size(av) > 1)
	{
		pmanp(av, exec_path);
		return ;
	}
	ft_putendl("Diese Shell wurde von Jérémy PEPIN (jpepin) erzeugt.");
	ft_putendl("Github : https://github.com/limaconoob");
	ft_putendl("Mail42 : jpepin@student.42.fr\n");
	ft_putendl("Dies sind die Builtins, daß Sie benutzen können :");
	ft_putendl("cd ; clear ; echo ; env ; exit ; ft_cat ; ft_grep ; ft_ls ; ");
	ft_putendl("help ; log ; manp ; pwd ; setenv ; unsetenv\n");
	ft_putendl("Viel Spaß ;)");
}
