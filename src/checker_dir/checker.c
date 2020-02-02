/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:16:21 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/02 12:52:10 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			main(int ac, char **av)
{
	int			*sta;
	int			*stb;
	t_mlst		*cmds;

	(ac == 1) ? exit(0) : 1;
	if (!(cmds = (t_mlst*)malloc(sizeof(t_mlst))))
		error();
	init_stacks(ac, av, &sta, &stb);
	(sta)[0] = 1;
	(stb)[0] = g_members + 1;
	read_i(cmds);
	result(cmds, sta, stb);
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
	while (get_next_line(0, &buf) > 0)
	{
		if (!(cmd_type = check_intruction(buf)))
			error();
		(i > 0) ? add_next(&cmds) : 1;
		cmds->num = cmd_type;
		i++;
		free(buf);
		buf = NULL;
	}
	free(buf);
	cmds->next = NULL;
	return (cmd_type);
}

int			check_intruction(const char *cmd)
{
	int	a;

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

void		result(t_mlst *cmds, int *sta, int *stb)
{
	int	i;

	while (cmds != NULL)
	{
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
	get_answer(sta, stb);
}

void		get_answer(int *sta, int *stb)
{
	int	i;

	if (stb[0] != g_members + 1)
	{
		answer(0);
	}
	i = sta[0];
	while (i < g_members)
	{
		if (sta[i] > sta[i + 1])
			answer(0);
		i++;
	}
	answer(1);
}
