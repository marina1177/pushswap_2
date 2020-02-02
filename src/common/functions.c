/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:19:31 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/02 12:53:47 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_stack(int *st)
{
	int	tmp;
	int	a;
	int	b;

	if (st[0] == g_members)
		return ;
	a = st[st[0]];
	b = st[st[0] + 1];
	tmp = a;
	st[st[0]] = b;
	st[st[0] + 1] = tmp;
}

void	swap_stacks(int *st1, int *st2)
{
	swap_stack(st1);
	swap_stack(st2);
}

void	push_stack(int *st1, int *st2)
{
	int	tmp;

	if (st2[0] == g_members + 1 || st1[0] == 1)
		return ;
	tmp = st2[st2[0]];
	st2[0]++;
	st1[0]--;
	st1[st1[0]] = tmp;
}

void	print_op(char *op)
{
	write(1, op, ft_strlen(op));
}
