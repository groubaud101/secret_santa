/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab_pseudo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:05:06 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/08 19:05:06 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_secret_santa.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	**ft_create_tab_pseudo(char *txt)
{
	int		fd;
	int		rd;
	char	buff[10000];
	char	**tab;

	fd = open(txt, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("fd fail");
		return (NULL);
	}
	rd = read(fd, buff, 10000);
	close(fd);
	buff[rd] = 0;
	tab = ft_split(buff, '\n');
	return (tab);
}