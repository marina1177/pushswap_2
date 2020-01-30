/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:53:25 by bcharity          #+#    #+#             */
/*   Updated: 2019/04/29 13:34:36 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_valid(const char *s, int n)
{
	int		i;
	const char	*str;
	char	*err;

	i = 0;
	str = s;
	while (*str >= 48 && *str <= 57)
	{
		i++;
		str++;
	}
	if (i > 18 && n == 1)
	{
		err = "Error(overflow(+1): atoi\n";
		write(2, err, ft_strlen(err));
		exit (0);
	}
	if (i > 18 && n == -1)
	{
		err = "Error(overflow(-1): atoi\n";
		write(2, err, ft_strlen(err));
		exit (0);
	}
	if ((*str < 48 || *str > 57) && *str != '\0')
	{
		err = "Error(Symbol is not a number):\n";
		write(2, err, ft_strlen(err));
		write(2, s, ft_strlen(s));
		write(2, "\n",1);
		exit (0);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int				n;
	long long int	val;

	val = 0;
	n = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		n = (*str == '-') ? -1 : 1;
		str++;
	}
	if (check_valid(str, n) <= 0)
		return (check_valid(str, n));
	while (*str >= 48 && *str <= 57)
	{
		val = 10 * val + (*str - 48);
		str++;
	}
	return (n * (int)val);
}
