/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:33:35 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/05 18:54:10 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_secret_santa.h"
#include <stdio.h>

int	ft_print_error(char *str)
{
	printf("ERROR\n%s\n", str);
	return (-1);
}

static int	ft_check_even_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (tab[i] != -1)
	{
		if (tab[i] == i)
			return (ft_print_error("Key == value"));
		if (tab[i] >= size || tab[i] < 0)
			return (ft_print_error("Value out of range"));
		i++;
	}
	return (1);
}

static int ft_tab_pseudo_len(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

int	main(int ac, char **av)
{
    t_santa	*santa;
	char	**tab;
	char	*txt;
    int		nb_santa;
    int		*tab_even;

	txt = "secret_santa_pseudo.txt";
	if (ac == 2)
		txt = av[1];

	tab = ft_create_tab_pseudo(txt);
	if (!tab)
		return (-1);
    nb_santa = ft_tab_pseudo_len(tab);
	//ft_aff_tab_pseudo(tab, nb_santa);

	santa = ft_create_database_santa(nb_santa, tab);
	if (!santa)
		return (-1);
	ft_aff_database_santa(santa);

	tab_even = ft_even_generator(nb_santa);
	if (ft_check_even_tab(tab_even, nb_santa) == -1)
		return (1);

	ft_send_mail(tab_even, santa, nb_santa);

	ft_free_santa(santa);
	ft_free_tab(tab, nb_santa);
	free(tab_even);
	return (0);
}