/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir_container.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:47:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 18:14:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_collector.h"

static void	ls_closedir(void *dirp)
{
	closedir((DIR *)dirp);
}

t_stack		*ls_dir_container(void)
{
	static t_stack	*st = NULL;

	if (!st)
	{
		st = ft_secmalloc(sizeof(t_stack));
		st->stack = NULL;
		st->size = 0;
		st->i = 0;
		st->cleanf = ls_closedir;
	}
	return (st);
}

void		ls_close_dir_stack(void)
{
	ft_collector(ls_dir_container(), NULL, FT_COLLEC_FREE);
}
