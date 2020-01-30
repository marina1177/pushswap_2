
#include "../../includes/push_swap.h"

int	main (int ac, char **av)
{
	int			*sta;
	int			*stb;
	t_mlst		*cmds;

	(ac == 1) ? exit(0) : 1;
	if (!(cmds = (t_mlst*)malloc(sizeof(t_mlst))))
		error();
	init_stacks(ac, av, &sta, &stb);

	(sta)[0] = 1;
	(stb)[0] = ac;

	read_i(cmds);
	//printf("end_read\n");
	result(cmds, sta, stb);
	//print_st(sta);
	exit(0);
}

int			read_i(t_mlst *cmds)
{
	char	*buf;
	int		cmd_type;
	int		*cmds_buf;
	int		i;

	i = 0;
	buf = NULL;
	cmds->prev = NULL;
	while (get_next_line(0, &buf) != 0)
	{
		if (ft_strlen(buf) == 0)
			break ;
		if (!(cmd_type = check_intruction(buf)))
		{
			//printf("cmd_type = %d\n", cmd_type);
			error();
		}
		//printf(".%d\n", cmd_type);
		(i > 0) ? add_next(&cmds) : 1;
		cmds->num = cmd_type;
		i++;
		free(buf);
		buf = NULL;
	}
	cmds->next = NULL;
	return (cmd_type);
}

int			check_intruction(const char *cmd)
{
	int a;

	a = 0;
	!ft_strcmp(cmd, "sa") ? (a = 1) : 1;
	!ft_strcmp(cmd, "sb") ? (a = 2) : 1;
	!ft_strcmp(cmd, "ss") ? (a = 3) : 1;
	!ft_strcmp(cmd, "pa") ? (a = 4) : 1;
	!ft_strcmp(cmd, "pb") ? (a = 5) : 1;
	!ft_strcmp(cmd, "ra") ? (a = 6) : 1;
	!ft_strcmp(cmd, "rb") ? (a = 7) : 1;
	!ft_strcmp(cmd, "rr") ? (a = 8) : 1;
	!ft_strcmp(cmd, "rra") ? (a = 9) : 1;
	!ft_strcmp(cmd, "rrb") ? (a = 10) : 1;
	!ft_strcmp(cmd, "rrr") ? (a = 11) : 1;
//	printf("a = %d\n", a);
	return (a);
}

void		result(t_mlst *cmds, int *sta, int *stb)
{
	int	i;
	//printf("result\n");
	while (cmds != NULL)
	{
		//printf("cmds->num = %d\n", cmds->num);

		(cmds->num == 1) ? swap_stack(sta) : 1;
		(cmds->num == 2) ? swap_stack(stb) : 1;
		(cmds->num == 3) ? swap_stacks(sta, stb) : 1;
		(cmds->num == 4) ? push_stack(sta, stb) : 1;
		(cmds->num == 5) ? push_stack(stb, sta) : 1;
		(cmds->num == 6) ? rot_stack(sta) : 1;
		(cmds->num == 7) ? rot_stack(stb) : 1;
		(cmds->num == 8) ? rot_stacks(sta, stb) : 1;
		(cmds->num == 9) ? revrot_stack(sta) : 1;
		(cmds->num == 10) ? revrot_stack(stb) : 1;
		(cmds->num == 11) ? revrot_stacks(sta, stb) : 1;
		cmds = cmds->next;
	}
	//print_st(sta);print_st(stb);
	if (stb[0] != g_members + 1)
		answer(0);
	i = sta[0];
	while (i < g_members)
	{
		//printf("%d_vs_%d\n",sta[i],sta[i+1]);
		if (sta[i] > sta[i + 1])
			answer(0);
		i++;
	}
	answer(1);
}

void		answer(int var)
{
	//printf("answer = %d\n", var);
	if(var == 1)
		ft_putstr("OK\n");
	else if (var == 0)
		ft_putstr("KO\n");
	exit(0);
}

void	add_next(t_mlst **curr)
{
	t_mlst *buf;

	//printf("add_next\n");
	buf = *curr;
	if (!((*curr)->next = (t_mlst*)malloc(sizeof(t_mlst))))
	{
		//printf("malloc_next\n");
		error();
	}
	*curr = (*curr)->next;
	(*curr)->prev = buf;
	(*curr)->next = NULL;
	(*curr)->num = 0;
}
