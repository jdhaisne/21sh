/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:55:04 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/04/22 16:33:40 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int ft_putchar_modif(int c)
{
ft_putchar(c);
return (0);
}
t_list	*double_tab_to_list(char **tab)
{
	int		i;
	t_list	*start;
	t_list	*tmp;

	i = 1;
	if (tab == NULL || tab[0] == NULL)
		return (NULL);
	start = ft_lstnew(tab[0], sizeof(char) * ft_strlen(tab[0]) + 1);
	tmp = start;
	while (tab[i]!= NULL)
	{
		tmp->next = ft_lstnew(tab[i], sizeof(char) * ft_strlen(tab[i]) + 1);
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	return (start);
}

int		main(int argc, char **argv, char **env)
{
	t_list	*env_l;
	char	*tmp;

	while(1)
	{
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (-1);

	tmp = tgetstr("cm", NULL);
//	ft_putstr(tmp);
	tputs(tgoto(tmp, 50, 50), 1, ft_putchar_modif);
//	ft_putchar(' ');
//	ft_putnbr(tgetnum("co"));
	ft_putchar('\n');
	}
	return (0);
}
