/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:23:04 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/20 16:23:04 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_secret_santa.h"

char	**ft_free_tab(char **tab, int len)
{
	while (len)
		free(tab[--len]);
	free(tab);
	return (NULL);
}

void	ft_free_santa(t_santa *santa)
{
	int	i;

	i = 0;
	while (santa[i].name)
	{
		free(santa[i].name);
		free(santa[i].mail);
		free(santa[i].lang);
		i++;
	}
	free(santa);
}
