/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_mail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:13:35 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/04 15:13:35 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_secret_santa.h"
#include <stdio.h>

// if there is a day when I'm capable to send mail in command line
// it will be call in this function

void	ft_mail(char *mail_user, char *mail_content)
{
	printf("Send mail to : %s\ncontent : |%s|\n\n",
			mail_user, mail_content);
}	

// concat the secret santa mail
// and the body of the message with the target name

int ft_send_mail(int *tab_even, char **tab_pseudo, int len)
{
	int i;
	char	mail_user[30];
	char	mail_content[30];

	i = 0;
	while (i < len)
	{
		sprintf(mail_user, "%s@student.s19.be", tab_pseudo[i]);
		sprintf(mail_content, "Your target is %s .", tab_pseudo[tab_even[i]]);
		ft_mail(mail_user, mail_content);
		i++;
	}
	return (1);
}
