/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:11:50 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/02 13:50:58 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	insertion_sort(int *a, int n)
{
	int	j;
	int	key;
	int	i;

	j = 1;
	while (j < n)
	{
		key = a[j];
		i = j - 1;
		while ((i >= 0) && (a[i] > key))
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
		j++;
	}
}

int		partition_2(int *a, int n, int x)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (j < (n - 1))
	{
		if (a[j] <= x)
		{
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			i++;
		}
		j++;
	}
	a[n - 1] = a[i];
	a[i] = x;
	return (i);
}

int		partition(int *a, int n, int x)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n)
	{
		if (a[i] == x)
		{
			a[i] = a[n - 1];
			a[n - 1] = x;
		}
		i++;
	}
	return (partition_2(a, n, x));
}
