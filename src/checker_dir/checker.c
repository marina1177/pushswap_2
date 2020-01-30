
#include "../../includes/push_swap.h"

/*
CHEKER:
-stack validation + error input
-reading & applying valid commands from stdin + command validation
-result output
*/

/*int find_startcheck(int ac,char **av)
{
	int	start;

	start = 0;
	while (av[start] && ft_strcmp(av[start], "./checker") != 0)
		start++;
	if (start == ac)
	{
		printf("not args for checker\n");
		exit (0);
	}
	return (start + 1);
}
void	arr_print(int *arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("arr[%d] = %d\n",i, arr[i]);
		i++;
	}
}*/

int	main (int ac, char **av)
{
	int			*sta;
	int			*stb;
	t_vector	*instrs;

	(ac == 1) ? exit(0) : 1;
	//init_stacks(ac, av, &sta, &stb);

	(sta)[0] = 1;
	(stb)[0] = ac;
	printf("checker\n");
	/*read_instructions(instrs);
	result(instrs, sta, stb);*/
	exit(0);
}

/*int			read_instructions(int *cmds)
{
	char	*buf;
	int		cmd_type;
	int		*cmds_buf;
	int		i;

	i = 0;
	buf = NULL;
	while (get_next_line(0, &buf) != 0)
	{
		if (!(cmd_type = check_intruction(buf)))
			error();
		(i > 0) ? add_next(&cmds) : 1;
		cmds->num = cmd_type;
		i++;
		free(buf);
		buf = NULL;
	}
	return (cmd_type);
}*/

/*int			check_intruction(const char *cmd)
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
	return (a);
}

void		result(t_vector	*instrs, int *sta, int *stb)
{
	while (cmds != NULL)
	{
		(cmds->num == 1) ? s_swap(&stack_one, 1, 0) : 1;
		(cmds->num == 2) ? s_swap(&stack_two, 2, 0) : 1;
		(cmds->num == 3) ? s_swap_both(&stack_one, &stack_two, 0) : 1;
		(cmds->num == 4) ? s_push(&stack_one, &stack_two, 1, 0) : 1;
		(cmds->num == 5) ? s_push(&stack_two, &stack_one, 2, 0) : 1;
		(cmds->num == 6) ? s_rotate(&stack_one, 1, 0) : 1;
		(cmds->num == 7) ? s_rotate(&stack_two, 2, 0) : 1;
		(cmds->num == 8) ? s_rotate_both(&stack_one, &stack_two, 0) : 1;
		(cmds->num == 9) ? s_rev_rotate(&stack_one, 1, 0) : 1;
		(cmds->num == 10) ? s_rev_rotate(&stack_two, 2, 0) : 1;
		(cmds->num == 11) ? s_rev_rotate_both(&stack_one, &stack_two, 0) : 1;
		cmds = cmds->next;
	}
	if (stack_two != NULL)
		answer(0);
	while (stack_one->next != NULL)
	{
		if (stack_one->num > stack_one->next->num)
			answer(0);
		stack_one = stack_one->next;
	}
	answer(1);
}

void		answer(_Bool var)
{
	var ? ft_printf("OK\n") : ft_printf("KO\n");
	exit(0);
}*/
