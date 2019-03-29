/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_acl_container.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:06:01 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 18:14:52 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/acl.h>
#include "ft_collector.h"

static void	ls_acl_free(void *aclp)
{
	acl_free(aclp);
}

t_stack		*ls_acl_container(void)
{
	static t_stack	*st = NULL;

	if (!st)
	{
		st = ft_secmalloc(sizeof(t_stack));
		st->stack = NULL;
		st->size = 0;
		st->i = 0;
		st->cleanf = ls_acl_free;
	}
	return (st);
}

void		ls_close_acl_stack(void)
{
	ft_collector(ls_acl_container(), NULL, FT_COLLEC_FREE);
}
