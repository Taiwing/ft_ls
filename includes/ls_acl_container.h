/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_acl_container.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:11:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 15:11:30 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_ACL_CONTAINER_H
# define LS_ACL_CONTAINER_H

# include "ft_collector.h"

t_stack	*ls_acl_container(void);
void	ls_close_acl_stack(void);

#endif
