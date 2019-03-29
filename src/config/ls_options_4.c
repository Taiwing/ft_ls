/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:13:54 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 14:28:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_options.h"

void	usage(t_lsconfig *cfg)
{
	ft_putstr_fd("usage: ls [-" OPTSTRING "] [file ...]\n", 2);
	ft_exit(NULL, cfg->ret);
}
