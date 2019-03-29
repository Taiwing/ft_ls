/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:00:29 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 15:51:39 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"
#include "lsfdata.h"
#include "libft.h"
#include "list_files.h"
#include "ls_sort.h"
#include "ls_print.h"
#include "ft_ls_errors.h"
#include "ls_dir_container.h"

static void	print_file_list(t_lsconfig *cfg, t_lsddata *lsd)
{
	t_lsfdata	*lsf;
	t_list		*cur;

	cur = lsd->ls_files;
	while (cur)
	{
		lsf = (t_lsfdata *)cur->content;
		cfg->ls_print_file(lsf, cfg);
		ft_lst_move_to_front(NULL, &cur, &cfg->ls_bank);
	}
	lsd->ls_files = NULL;
	flush_pbuf(&cfg->buf);
}

char		*build_path(const char *old_path, const char *dirname)
{
	char	*path;

	path = NULL;
	if (old_path && *old_path && ft_strcmp(old_path, "/"))
	{
		path = (char *)ft_strnew(ft_strlen(old_path) + 1 + ft_strlen(dirname));
		ft_strcat(path, old_path);
		ft_strcat(path, "/");
		ft_strcat(path, dirname);
	}
	else if (old_path && *old_path)
	{
		path = (char *)ft_strnew(1 + ft_strlen(dirname));
		ft_strcat(path, "/");
		ft_strcat(path, dirname);
	}
	else
		return (ft_strdup(dirname));
	return (path);
}

void		list_dir(t_lsconfig *cfg, const char *path, const char *dirname)
{
	int			len;
	t_lsddata	lsd;

	len = 0;
	lsd.path = build_path(path, dirname);
	ls_print_dir(cfg, lsd.path);
	if (!(lsd.dirp = opendir(lsd.path)))
	{
		put_opendir_error(lsd.path, cfg);
		free(ft_heap_collector(lsd.path, FT_COLLEC_GET));
		return ;
	}
	ft_collector(ls_dir_container(), lsd.dirp, FT_COLLEC_ADD);
	cfg->list_files(cfg, &lsd, &len);
	print_errors(cfg);
	if (cfg->sortf)
		cfg->sortf(lsd.ls_files, cfg, len);
	print_file_list(cfg, &lsd);
	free(ft_heap_collector(lsd.path, FT_COLLEC_GET));
	closedir((DIR *)ft_collector(ls_dir_container(), lsd.dirp, FT_COLLEC_GET));
}

void		list_first_dir(t_lsconfig *cfg)
{
	int			len;
	t_lsddata	lsd;

	len = 0;
	lsd.path = cfg->args_len ? cfg->args[0] : ".";
	if (!(lsd.dirp = opendir(lsd.path)))
	{
		put_opendir_error(lsd.path, cfg);
		return ;
	}
	ft_collector(ls_dir_container(), lsd.dirp, FT_COLLEC_ADD);
	cfg->list_files(cfg, &lsd, &len);
	print_errors(cfg);
	if (cfg->sortf)
		cfg->sortf(lsd.ls_files, cfg, len);
	print_file_list(cfg, &lsd);
	closedir((DIR *)ft_collector(ls_dir_container(), lsd.dirp, FT_COLLEC_GET));
}
