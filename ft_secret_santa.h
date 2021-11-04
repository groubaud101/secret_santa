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

int	*ft_even_generator(int size, int max);
int ft_send_mail(int *tab_even, char **tab_pseudo, int len);

#endif