/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libopt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:34:07 by rbernand          #+#    #+#             */
/*   Updated: 2016/03/17 19:03:27 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBOPT_H
# define LIBOPT_H

# include <stdint.h>

# define STOP_DELIMITER		"--"

enum		e_type_opt
{
	_OPT_UNDEF = 0,
	_OPT_BOOL = 1,
	_OPT_COUNT,
	_OPT_INT,
	_OPT_STR,
	_OPT_FLOAT,
	_OPT_MAX
};

typedef struct s_opt	t_opt;

struct					s_opt
{
	t_opt				*next;
	char				c;
	enum e_type_opt		type;
	void				*dst;
};

extern t_opt				*g_opt_list;

int							store_opt(char c, enum e_type_opt type, void *dst);
int							parse_opt(int ac, char **av);

#endif
