/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 12:42:39 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/02 13:00:48 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t		count_word(char const *s, char c)
{
	char	*p;
	size_t	lns;

	if (!s)
		return (0);
	lns = 0;
	p = (char*)s;
	while (*p != '\0')
	{
		if (*p != c && (*(p + 1) == c || *(p + 1) == '\0'))
			lns++;
		p++;
	}
	return (lns);
}

void		error(void)
{
	char *s;

	s = "Error\n";
	write(2, s, ft_strlen(s));
	exit(0);
}

void		add_next(t_mlst **curr)
{
	t_mlst *buf;

	buf = *curr;
	if (!((*curr)->next = (t_mlst*)malloc(sizeof(t_mlst))))
	{
		error();
	}
	*curr = (*curr)->next;
	(*curr)->prev = buf;
	(*curr)->next = NULL;
	(*curr)->num = 0;
}

void		answer(int var)
{
	if (var == 1)
		ft_putstr("OK\n");
	else if (var == 0)
		ft_putstr("KO\n");
	exit(0);
}
