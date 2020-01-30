#include "../../includes/push_swap.h"


void	check_repeat(int *st, int val)
{
	int	i;

	i = st[0] - 1;
	//printf("check_repeat_st[0] = %d\n", st[0]);
	while (i > 0)
	{
		//printf("st[%d] = %d\n",i, st[i]);
		if (st[i] == val)
			error();
		i--;
	}
}

int		check_arg(int *sta, char **curr, int *len)
{
	int			val;
	int			k;

	k = 0;
	while(curr[k] != NULL)
	{
		//printf("curr_k[%d] = %s\n",k, curr[k]);
		val = ft_atoi(curr[k]);
		if(*len > 0)
		{
			check_repeat(sta, val);
		}
		sta[sta[0]] = val;
		free(curr[k]);
		(*len)++;
		k++;
	}
	free(curr);
}

int		fill_sta(int ac, char **av, int *sta)
{
	int		i;
	int		num;
	char	**curr;

	i = 1;
	num = 0;
	while (i < ac)
	{
		curr = ft_strsplit(av[i], ' ');
		//printf("curr[%d] = %s\n",i, *curr);
		sta[0] = i;
		check_arg(sta, curr, &num);
		i++;
	}
	return (num);
}

void	init_stacks(int argc, char *argv[], int **sta, int **stb)
{
	int	i;

	if (!(*sta = (int*)malloc(sizeof(int)*(argc)))
		|| !(*stb = (int*)malloc(sizeof(int)*(argc))))
		error();
	(*sta)[0] = 1;
	(*stb)[0] = argc;

	g_members =	fill_sta(argc, argv, *sta);
	(*sta)[0] = 1;
	(*stb)[0] = g_members + 1;
	i = 1;
	while (i < argc)
	{
		(*stb)[i] = 0;
	//	printf("%d ", (*sta)[i]);
		i++;
	}//printf("\n");

}
