/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_database_santa.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:38:05 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/20 15:38:05 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_secret_santa.h"

t_santa	*ft_create_database_santa(int nb_santa, char **tab_line)
{
	char	**tmp_tab;
	int		i;
	t_santa	*santa;

	santa = (t_santa *)malloc(sizeof(*santa) * (nb_santa + 1));
	if (!santa)
		return (NULL);
	i = 0;
	while (tab_line[i])
	{
		santa[i].index = i;
		tmp_tab = ft_split(tab_line[i], ':');
		santa[i].name = strdup(tmp_tab[NAME]);
		santa[i].mail = strdup(tmp_tab[MAIL]);
		santa[i].lang = strdup(tmp_tab[LANG]);
		free(tmp_tab);
		i++;
	}
	santa[i].name = NULL;
	return (santa);
}