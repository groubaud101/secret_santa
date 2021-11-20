/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:38 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/20 16:05:38 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_secret_santa.h"

void	ft_aff_tab_pseudo(char **tab, int nb_santa)
{
	int	i;

	i = 0;
	printf("Tab_pseudo :\nnb_santa : %i\n", nb_santa);
	while (tab[i])
	{
		printf("tab_pseudo[%02i] : |%s|\n", i, tab[i]);
		i++;
	}
	printf("\n");
}

void	ft_aff_database_santa(t_santa *santa)
{
	int	i;

	i = 0;
	printf("Database Secret Santa :\n");
	while (santa[i].name)
	{
		printf("Num %i, name : %s, mail : %s, lang : %s\n",
			santa[i].index, santa[i].name, santa[i].mail, santa[i].lang);
		i++;
	}
}