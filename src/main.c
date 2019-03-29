/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:00:17 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 15:58:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_option_parser.h"
#include "get_args.h"
#include "ls_dir_container.h"
#include "ls_acl_container.h"

int	main(int argc, char **argv)
{
	t_lsconfig	cfg;

	ft_atexit(ls_close_dir_stack);
	ft_atexit(ls_close_acl_stack);
	init_lsconfig(&cfg);
	ls_option_parser(&cfg, argc, argv);
	cfg.get_arguments(&cfg);
	flush_pbuf(&cfg.buf);
	ft_atexit(NULL);
	ft_heap_collector(NULL, FT_COLLEC_FREE);
	return (cfg.ret);
}
