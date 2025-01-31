/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:19:18 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/02 12:55:34 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		check_repeat(int *st, int val)
{
	int	i;

	i = st[0] - 1;
	while (i > 0)
	{
		if (st[i] == val)
			error();
		i--;
	}
}

void		check_arg(int *sta, char **curr, int *len)
{
	int			val;
	int			k;

	k = 0;
	while (curr[k] != NULL)
	{
		val = ft_atoi(curr[k]);
		if (*len > 0)
		{
			check_repeat(sta, val);
		}
		sta[sta[0]] = val;
		sta[0] += 1;
		free(curr[k]);
		(*len)++;
		k++;
	}
	free(curr);
}

int			calc_members(int ac, char **av)
{
	int		i;
	int		num;
	char	**curr;

	i = 1;
	num = 0;
	while (i < ac)
	{
		num += count_word(av[i], ' ');
		i++;
	}
	return (num);
}

int			fill_sta(int ac, char **av, int *sta)
{
	int		i;
	int		k;
	int		num;
	char	**curr;

	i = 1;
	num = 0;
	while (i < ac)
	{
		curr = ft_strsplit(av[i], ' ');
		k = 0;
		check_arg(sta, (curr), &num);
		i++;
	}
	return (num);
}

void		init_stacks(int argc, char *argv[], int **sta, int **stb)
{
	int	i;
	int	flg;

	g_members = calc_members(argc, argv);
	if (!(*sta = (int*)malloc(sizeof(int) * (g_members + 1)))
		|| !(*stb = (int*)malloc(sizeof(int) * (g_members + 1))))
		error();
	(*sta)[0] = 1;
	fill_sta(argc, argv, *sta);
	(*sta)[0] = 1;
	(*stb)[0] = g_members + 1;
	i = 1;
	while (i <= g_members)
	{
		(*stb)[i] = 0;
		i++;
	}
}
