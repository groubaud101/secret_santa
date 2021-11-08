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

void	ft_aff_tab_pseudo(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("tab_pseudo[%02i] : |%s|\n", i, tab[i]);
		i++;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
    char	**tab_pseudo;
	char	*txt;
    int		tab_len;
    int		*tab_even;

	txt = "secret_santa_pseudo.txt";
	if (ac == 2)
		txt = av[1];
	tab_pseudo = ft_create_tab_pseudo(txt);
	ft_aff_tab_pseudo(tab_pseudo);
    tab_len = ft_tab_pseudo_len(tab_pseudo);
	tab_even = ft_even_generator(tab_len, tab_len);
	if (ft_check_even_tab(tab_even, tab_len) == -1)
		return (1);
	ft_send_mail(tab_even, tab_pseudo, tab_len);
	return (0);
}