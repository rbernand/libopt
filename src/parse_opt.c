/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:50:45 by rbernand          #+#    #+#             */
/*   Updated: 2016/03/17 19:59:13 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libopt.h"

static int				save_opt(t_opt *opt, char *param)
{
	if (opt->type == _OPT_BOOL)
		*(uint8_t *)opt->dst = !(*(uint8_t *)opt->dst);
	else if (opt->type == _OPT_COUNT)
		(*(uint8_t *)opt->dst)++;
	else if (opt->type == _OPT_INT && param)
		*(int *)opt->dst = atoi(param);
	else if (opt->type == _OPT_STR && param)
	{
		if (param[0] == '-')
			return (-1);
		*(char **)opt->dst = strdup(param);
	}
	else if (opt->type == _OPT_FLOAT && param)
		*(float *)opt->dst = atof(param);
	else
		return (-1);
	return (0);
}

static t_opt			*find_opt(char c)
{
	t_opt			*lst;
	
	lst = g_opt_list;
	while (lst)
	{
		if (lst->c == c)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int						parse_opt(int ac, char **av)
{
	int32_t			i;
	uint32_t			j;
	t_opt				*opt;

	i = 1;
	while (i < ac)
	{
		if (strcmp(av[i], STOP_DELIMITER) == 0)
			break ;
		if (av[i][0] == '-')
		{
			j = 0;
			while (av[i][++j])
			{
				if ((opt = find_opt(av[i][j])) == NULL)
				{
					dprintf(2, "Invalid option: '%c'\n", av[i][j]);
					return (-1);
				}
				if (save_opt(opt, av[i + 1]) < 0)
				{
					dprintf(2, "option '%c' - parameter is missing.\n", opt->c);
					return (-1);
				}
			}
		}
	}
	return (0);
}
