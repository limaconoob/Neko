/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 03:18:31 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/10 20:01:10 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

char			***files_malloc(int size)
{
	char		***files;

	if (!(files = (char***)malloc(sizeof(char**) * (size + 1))))
		ls_error(Malloc, "files");
	files[size] = NULL;
	return (files);
}
