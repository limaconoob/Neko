/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soptions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 02:21:17 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 07:14:32 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			glong(char *longarg, int *options)
{
	if (!ft_strcmp(longarg, "recursive"))
		options[R] = 1;
	else if (!ft_strcmp(longarg, "all"))
		options[a] = 1;
	else if (!ft_strcmp(longarg, "format=long"))
		options[l] = 1;
	else if (!ft_strcmp(longarg, "format=verbose"))
		options[l] = 1;
	else if (!ft_strcmp(longarg, "reverse"))
		options[r] = 1;
	else if (!ft_strcmp(longarg, "sort=time"))
		options[t] = 1;
	else if (!ft_strcmp(longarg, "format=single-column"))
		options[1] = 1;
	else
	{
		ls_error(Usagelong, longarg);
		return (-1);
	}
	return (0);
}

static int			goptions(int cur_arg, char **av, int *options)
{
	int				cur_opt;
	int				parse;
	char			*set;

	set = "R1alrt";
	cur_opt = 0;
	while (++cur_opt && av[cur_arg][cur_opt])
	{
		parse = 0;
		while (parse < 5 && set[parse] != av[cur_arg][cur_opt])
			parse++;
		if (set[parse] == av[cur_arg][cur_opt])
			options[parse] = 1;
		else
		{
			ls_error(Usage, &(av[cur_arg][cur_opt]));
			return (-1);
		}
	}
	return (0);
}

int					soptions(int ac, char **av, int *options)
{
	int				cur_opt;
	int				cur_arg;

	cur_opt = -1;
	while (++cur_opt < 6)
		options[cur_opt] = 0;
	cur_arg = 0;
	while (++cur_arg < ac && av[cur_arg][0] == '-' && av[cur_arg][1])
	{
		if (av[cur_arg][1] == '-' && !av[cur_arg][2])
		{
			cur_arg++;
			break ;
		}
		else if (av[cur_arg][1] == '-' && av[cur_arg][2])
		{
			if (glong(&av[cur_arg][2], options) == -1)
				return (-1);
		}
		else if (goptions(cur_arg, av, options) == -1)
			return (-1);
	}
	return (cur_arg);
}
