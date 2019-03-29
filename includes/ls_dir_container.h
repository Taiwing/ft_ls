/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir_container.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:03:14 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 15:04:50 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_DIR_CONTAINER_H
# define LS_DIR_CONTAINER_H

# include "ft_collector.h"

t_stack	*ls_dir_container(void);
void	ls_close_dir_stack(void);

#endif
