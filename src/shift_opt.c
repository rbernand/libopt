/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:32:50 by rbernand          #+#    #+#             */
/*   Updated: 2016/03/17 19:45:15 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libopt.h"

void			shift_opt(int *ac, char **av)
{
	uint32_t		i;
	uint32_t		len_av;
	uint32_t		len;
	uint32_t		new_ac;

	len_av = 0;
	i = 0;
	while (++i < *ac)
		len_av += strlen(av[i]);

	new_ac = 0;
	i = 0;
	while (++i < *ac)
	{
		
	}
}
