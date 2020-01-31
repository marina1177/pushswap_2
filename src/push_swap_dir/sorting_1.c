/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:29:45 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/01 00:58:18 by bcharity         ###   ########.fr       */
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
	while(i <= g_members)
	{
		k = (*sta)[0];
		if ((*sta)[k] >= m )
		{
			if (check_bottom_a(*sta, g_members - count, m) == 0)
				break ;
			rot_stack(*sta);
			print_op("ra\n");
		}
		else if ((*sta)[k] < m )
		{
			push_stack(*stb, *sta);
			print_op("pb\n");
			count++;
		}
		i++;
	}
	return(count);
}

int		begin_pyramid(int **sta, int **stb, int *arr)
{
	int	median;
	int	i;
	int	*num_b;

	i = 0;
	num_b = arr;
	while(i < (g_members / 2))
	{
		num_b[i] = 0;
		i++;
	}
	while ((i = (g_members - (*sta)[0] + 1)) > 3)
	{
		median = get_m(*sta, g_members);
		num_b[0]++;
		num_b[num_b[0]] = devide_a(sta, stb, median);
	}
	return(i);
}

int		sorting(int **sta, int **stb)
{
	int	i;
	int	num_b[g_members/2];

	i = begin_pyramid(sta, stb, &(num_b[0]));
	sortcarry_a(*sta, i);
	parse_b(*sta, *stb, num_b);
	return(0);
}


