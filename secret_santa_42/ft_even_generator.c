/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_even_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:55:48 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/04 14:55:48 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

static void	ft_aff_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("tab[%i] = %i\n", i, tab[i]);
		i++;
	}
	write(1, "\n", 1);
}

static int	rand_a_number(int max)
{
	static int	rand_is_seeded = 0;

	if (!rand_is_seeded)
	{
		srand(time(NULL));
		rand_is_seeded = 1;
	}
	return (rand() % max);
}

static int	*ft_init_tab(int size)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(*tab) * (size + 1));
	if (!tab)
		return (NULL);
	while (i <= size)
		tab[i++] = -1;
	return (tab);
}

static int	*ft_generate_diff_nb(int *tab, int size, int max)
{
	int i;
	int	j;
	int	r;

	i = 0;
	while (i < size)
	{
		j = 0;
		r = rand_a_number(max);
		while (j < i)
		{
			if (tab[j] == r)
				break ;
			j++;
		}
		if (tab[j] != r)
		{
			tab[j] = r;
			i++;
		}
	}
	return (tab);
}

static void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*ft_diff_key_value(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == i
		|| tab[i + 1] == i + 1)
			ft_swap(&tab[i], &tab[i + 1]);
		i++;
	}
	return (tab);
}

int	*ft_even_generator(int size, int max)
{
	int	*tab;

	tab = ft_init_tab(size);
	printf("tab apres init\n");
	ft_aff_tab(tab, size);

	tab = ft_generate_diff_nb(tab, size, max);
	printf("tab apres genereate\n");
	ft_aff_tab(tab, size);

	tab = ft_diff_key_value(tab, size);
	printf("tab apres diff_key_value\n");
	ft_aff_tab(tab, size);
	return (tab);
}
