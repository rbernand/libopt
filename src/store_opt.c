/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:36:10 by rbernand          #+#    #+#             */
/*   Updated: 2016/03/17 19:22:30 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libopt.h"

t_opt				*g_opt_list = NULL;

static t_opt		*new_opt(char c, enum e_type_opt type, void *dst)
{
	t_opt			*new;

	new = (t_opt *)malloc(sizeof(t_opt));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->c = c;
	new->type = type;
	new->dst = dst;
	return (new);
}

int					store_opt(char c, enum e_type_opt type, void *dst)
{
	t_opt			*lst;

	if (dst == NULL)
	{
		dprintf(2, "destination is NULL.\n");
		return (-1);
	}
	lst = g_opt_list;
	while (lst)
	{
		if (lst->c == c)
		{
			dprintf(2, "Character '%c' already set.\n", c);
			return (-1);
		}
		lst = lst->next;
	}
	lst = new_opt(c, type, dst);
	lst->next = g_opt_list;
	g_opt_list = lst;
	return (0);
}
