/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secret_santa.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:34:56 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/04 14:34:56 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECRET_SANTA_H
# define SECRET_SANTA_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define NAME 0
# define MAIL 1
# define LANG 2

# define EN 0
# define FR 1

typedef struct s_santa
{
	int 	index;
	char	*name;
	char	*mail;
	char	*lang;
}t_santa;

void	ft_aff_tab_pseudo(char **tab, int nb_santa);
void	ft_aff_database_santa(t_santa *santa);

int		ft_print_error(char *str);

char	**ft_create_tab_pseudo(char *txt);

t_santa	*ft_create_database_santa(int nb_santa, char **tab_line);

int		*ft_even_generator(int size);

int 	ft_send_mail(int *tab_even, t_santa *santa, int len);

char	**ft_free_tab(char **tab, int len);
void	ft_free_santa(t_santa *santa);

#endif