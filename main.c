/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:33:35 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/04 14:33:35 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_secret_santa.h"
#include <stdio.h>

static int	ft_print_error(char *str)
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
    char *tab_pseudo[] = {"groubaud",
                    "afulmini",
                    "mykman",
                    "pvanderl",
                    "cmillet",
                    "jdecorte",
                    NULL};
    int tab_len;
    int *tab_even;

    tab_len = ft_tab_pseudo_len(tab_pseudo);
	tab_even = ft_even_generator(tab_len, tab_len);
	if (ft_check_even_tab(tab_even, tab_len) == -1)
		return (1);
	ft_send_mail(tab_even, tab_pseudo, tab_len);
	return (0);
}