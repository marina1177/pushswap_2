/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:52:44 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/02 17:42:21 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		separate_a(int *sta, int *stb, int *num_b, int *num_a)
{
	int	ma;
	int	count_a;
	//int	*enda;
	int	i;
	int	enda;

	//printf("separate_a\n");
	//print_st(sta);print_st(stb);

	//enda = &(sta[sta[0] + *num_a - 1]);
	enda = sta[0] + *num_a - 1;
	count_a = 0;
	ma = get_m(sta, sta[0] + *num_a - 1);
	i = sta[0];
	//printf("ma = %d\n", ma);
	while (i <= enda)
	{
		if (sta[sta[0]] < ma)
		{
			push_stack(stb, sta);
			print_op("pb\n");
			num_b[num_b[0]]++;
			(*num_a)--;
		}
		else if (sta[sta[0]] >= ma)
		{
			/*if ((check_bottom_a(sta, enda, ma)) == 0)
				break ;*/
			rot_stack(sta);
			print_op("ra\n");
			count_a++;
		}
		i++;
	}
	return (count_a);
}

void	parse_a(int *sta, int *stb, int *num_b, int num_a)
{
	int	ma;
	int	count_a;
	int	*enda;

	/*printf("parse_a\n");
	printf("num_a = %d\n", num_a);*/
	if (num_a <= 3)
	{
		parse_carry_a(sta, num_a);
		return ;
	}
	while (num_a > 3)
	{
		num_b[0]++;
		num_b[num_b[0]] = 0;
		count_a = separate_a(sta, stb, num_b, &num_a);
		//printf("count_a = %d\n", count_a);
		while (count_a > 0)
		{
			revrot_stack(sta);
			print_op("rra\n");
			count_a--;
		}
	}
}

void	put_back_b(int *stb, int *num_b, int cnt_b)
{
	int i;

	i = 0;
	while (i < cnt_b && (num_b[0] > 1))
	{
		revrot_stack(stb);
		print_op("rrb\n");
		i++;
	}
}

void	separate_b(int *sta, int *stb, int *num_b, int cnt[2])
{
	int	var[4];

	var[3] = num_b[num_b[0]];
	var[2] = stb[0] + var[3] - 1;
	var[1] = get_m(stb, stb[0] + var[3] - 1);
	var[0] = stb[0];
	while (var[0] <= var[2])
	{
		if (stb[stb[0]] >= var[1])
		{
			push_stack(sta, stb);
			print_op("pa\n");
			cnt[0]++;
			num_b[num_b[0]]--;
		}
		else if (stb[stb[0]] < var[1])
		{
			if ((check_bottom_b(stb, var[3] - cnt[0], var[1])) == 0)
				break ;
			rot_stack(stb);
			print_op("rb\n");
			cnt[1]++;
		}
		var[0]++;
	}
}

void	parse_b(int *sta, int *stb, int *num_b)
{
	int	mb;
	int	i;
	int	endb;
	int	count[2];

	while (num_b[0] > 0)
	{
		if (num_b[num_b[0]] <= 3)
		{
			pushcarry(sta, stb, num_b[num_b[0]]);
			num_b[num_b[0]] = 0;
			num_b[0]--;
			if (num_b[0] > 0)
				continue ;
			return ;
		}
		count[0] = 0;
		count[1] = 0;
		separate_b(sta, stb, num_b, &(count[0]));
		put_back_b(stb, num_b, count[1]);
		parse_a(sta, stb, num_b, count[0]);
	}
}
