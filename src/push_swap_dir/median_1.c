/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:30:32 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/02 14:08:46 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		fun_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int		get_m(int *st, int n)
{
	int	*tmp;
	int	size;
	int	res;

	size = n - st[0] + 1;
	tmp = ft_memalloc(size * sizeof(int));
	ft_memcpy(tmp, &(st[st[0]]), size * sizeof(int));
	res = sel_m(tmp, size / 2, size);
	free(tmp);
	return (res);
}

void	sel_m_2(int *a, int n, int *var)
{
	(var)[0] = 0;
	(var)[1] = 0;
	while ((var)[1] < n)
	{
		(var)[2] = fun_min(5, n - (var)[1]);
		insertion_sort(a + (var)[1], (var)[2]);
		(var)[3] = a[(var)[1] / 5];
		a[(var)[1] / 5] = a[(var)[1] + (var)[2] / 2];
		a[(var)[1] + ((var)[2]) / 2] = (var)[3];
		(var)[0]++;
		(var)[1] += 5;
	}
}

int		sel_m(int *a, int i, int n)
{
	int	var[6];

	if (n == 1)
		return (a[0]);
	sel_m_2(a, n, &(var[0]));
	if (var[0] > 1)
		var[4] = sel_m(a, var[0] / 2, var[0]);
	else
		var[4] = a[0];
	var[5] = partition(a, n, var[4]);
	if (var[5] == i)
		return (var[4]);
	else if (i < var[5])
		return (sel_m(a, i, var[5]));
	return (sel_m(a + var[5], i - var[5], n - var[5]));
}
