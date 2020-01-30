/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_sta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:29:45 by bcharity          #+#    #+#             */
/*   Updated: 2020/01/29 21:38:13 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		devide_a(int **sta, int **stb, int m)
{
	int	count;
	int	i;
	int	k;

	count = 0;
	i = (*sta)[0];
	//printf("i_start = %d\n",i);
	while(i <= g_members)
	{
		k = (*sta)[0];
		//printf("(*sta)[%d] = %d__m = %d\n", k, (*sta)[k], m);

		if ((*sta)[k] >= m)
		{
			rot_stack(*sta);
			print_op("ra\n");//print_st(*sta);print_st(*stb);
		}
		else if ((*sta)[k] < m)
		{
			push_stack(*stb, *sta);
			print_op("pb\n");//print_st(*sta);print_st(*stb);
			count++;
		}
		i++;
	}
	return(count);
}

int		split_a_mdn0(int **sta, int **stb)
{
	int	median;
	int	i;
	int	num_b[g_members/2];

	i = 0;
	while(i < (g_members / 2))
	{
		num_b[i] = 0;
		i++;
	}

	while ((i = (g_members - (*sta)[0] + 1)) > 3)
	{
		//printf("i = %d\n", i);
		median = get_m(*sta, g_members);
		//printf("median = %d\n", median);
		//print_st(*sta);
		num_b[0]++;
		num_b[num_b[0]] = devide_a(sta, stb, median);
		//printf("num_b[%d] = %d\n", num_b[0],num_b[num_b[0]]);
	}
      /*printf("sortcarry\n");
	  printf("i = %d\n", i);*/
	sortcarry(*sta, i);
	//printf("after_sortcarry\n");

	//print_st(*sta);print_st(*stb);

	parse_b(*sta, *stb, num_b);

	return(0);
}


void	parse_b(int *sta, int *stb, int *num_b)
{
	//int	num_a[g_members/2];
	int	mb;
	int	i;
	int	endb;
	int	count_b;
	int	count_a;

	while(num_b[0] > 0)
	{
		//printf("num_b[%d]= %d\n", num_b[0], num_b[num_b[0]]);

		if (num_b[num_b[0]] <= 3)
		{
			//printf("pushcarry\n");print_st(sta);print_st(stb);
			pushcarry(sta, stb, num_b[num_b[0]]);
			//printf("after_pushcarry\n"); print_st(sta);print_st(stb);
			num_b[num_b[0]] = 0;
			num_b[0]--;
			if(num_b[0] > 0)
				continue ;
			return ;
		}
		////////////////////////////////////////////////
		int delta = num_b[num_b[0]];
		count_a = 0;
		count_b = 0;
		endb = stb[0] + delta - 1;
		mb = get_m(stb, stb[0] + delta - 1);
		/*printf("mb = %d\n", mb);
		printf("endb = %d\n", endb);
		printf("stb[0] = %d\n", stb[0]);*/
		i = stb[0];
		while (i <= endb)
		{
			//printf("i = %d\n", i);
			if(stb[stb[0]] >= mb)
			{
				push_stack(sta, stb);
				//print_op("pa\n");print_st(sta);print_st(stb);
				count_a++;
				num_b[num_b[0]]--;
			}
			else if (stb[stb[0]] < mb)
			{
				if ((check_bottom_b(stb, delta - count_a, mb)) == 0)
					break ;
				rot_stack(stb);
				//print_op("rb\n");print_st(sta);print_st(stb);
				count_b++;
			}
			i++;
		}
		/*printf("count_a = %d\n", count_a);
		printf("count_b = %d\n", count_b);*/
		//last el_b
		int i = 0;
		while (i < count_b && (num_b[0] > 1))
		{
			revrot_stack(stb);
			//print_op("rrb\n");print_st(sta);print_st(stb);
			i++;
		}
		//print_st(sta);print_st(stb);
		/*printf("num_b[%d] = %d\n", num_b[0], num_b[num_b[0]]);
		printf("parse_a\n");*/
		parse_a(sta, stb, num_b, count_a);
		//print_st(sta);print_st(stb);
	}
}

void	parse_a(int *sta, int *stb, int *num_b, int num_a)
{
	int	delta;
	int	ma;
	int	*pa;
	int	count_a;
	int	*enda;

	if (num_a <= 3)
	{
		parse_carry_a(sta, num_a);
		return ;
	}

	while (num_a > 3)
	{
		enda = &(sta[sta[0] + num_a - 1]);
		count_a = 0;
		ma = get_m(sta, sta[0] + num_a - 1);
		num_b[0]++;
		num_b[num_b[0]] = 0;
		while(&(sta[sta[0]]) != enda)
		{
			if (sta[sta[0]] <= ma)
			{
				push_stack(stb, sta);
				print_op("pb\n");//print_st(sta);
				num_b[num_b[0]]++;
				num_a--;
			}
			else
			{
				rot_stack(sta);
				print_op("ra\n");//print_st(sta);
				count_a++;
			}
		}
		while (count_a > 0)
		{
			revrot_stack(stb);
			print_op("rrb\n");//print_st(sta);
			count_a--;
		}
	}
}

