/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_mail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:13:35 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/05 19:02:35 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_secret_santa.h"

// send the mail, stock a copy in secret_santa.log

void	ft_mail(char *mail_user, char *mail_content)
{
	FILE	*fd;
	// char	cmd[150];

	fd = fopen("secret_santa.log", "a+");
	fprintf(fd, "Send mail to : %s\ncontent : %s\n",
			mail_user, mail_content);
	printf("Send mail to : %s\ncontent : %s\n",
			mail_user, mail_content);
/*
	sprintf(cmd, "echo %s | mail -s %s %s",
				mail_content,
				"TEST_secret_santa_TEST",
				mail_user);
	system(cmd);
*/
}	

// concat the secret santa mail
// and the body of the message with the target name

int	ft_check_lang(char *lang)
{
	if (lang[0] == 'E' && lang[1] == 'N')
		return (EN);
	else if (lang[0] == 'F' && lang[1] == 'R')
		return (FR);
	else
		return (-1);
}

int ft_send_mail(int *tab_even, t_santa *santa, int len)
{
	int i;
	char	mail_user[30];
	char	mail_content[300];

	i = 0;
	remove("secret_santa.log");
	while (i < len)
	{
		sprintf(mail_user, "%s", santa[i].mail);
		if (ft_check_lang(santa[i].lang) == EN)
			sprintf(mail_content, "Good day, your secret Santa's target is %s.\nMerry Christmas !\n",
				santa[tab_even[i]].name);
		else if (ft_check_lang(santa[i].lang) == FR)
			sprintf(mail_content, "Bonjour, votre cible du père Noël secret est %s.\nJoyeux Noël !\n",
				santa[tab_even[i]].name);
		ft_mail(mail_user, mail_content);
		i++;
	}
	return (1);
}
