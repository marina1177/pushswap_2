#include "../../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	int	*sta;
	int	*stb;
	int	i;

	init_stacks(argc, argv, &sta, &stb);
	if (!ordered(sta))
	{
		sorting(&sta, &stb);
	}
	exit(0);
	return 0;
}

int		ordered(int *s)
{
	int		buf[4];
	int		*tmp;
	int		i;

	buf[0] = s[g_members];
	buf[1] = 0;
	buf[3] = 0;
	i = s[0];
	while (i <= g_members)
	{
		if (buf[0] > s[i])
		{
			buf[1]++;
			buf[2] = s[i];
		}
		buf[0] = s[i];
		i++;
	}
	if (buf[1] > 1)
		return (0);
	(buf[1] == 1) ? rotate(s, g_members, buf[2]) : 1;
	return (1);
}

void	rotate(int *s, int len, int min)
{
	int	*tmp;
	int		pos;

	tmp = &(s[s[0]]);
	pos = 0;
	while (*tmp != min)
	{
		pos++;
		tmp++;
	}
	if (pos > len / 2)
		while (s[s[0]] != min)
		{
			revrot_stack(s);
			print_op("rra\n");
		}
	else
		while (s[s[0]] != min)
		{
			rot_stack(s);
			print_op("ra\n");
		}
}


