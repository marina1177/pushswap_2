#include "../../includes/push_swap.h"

char *g_avinstrs[11] = {"sa", "sb", "ss",
						"pa", "pb",
						"ra", "rb", "rr",
						"rra", "rrb", "rrr"};

static void	vec_print(t_vector	*vec)
{
	int i = 0;

	while (i < vec->count)
	{
		printf(">\n");
		printf("vec.data[%d] = %s\n",i, (char*)vec->data[i]);
		/*printf("vec.count[%d] = %d\n",i, vec->count);
		printf("vec.size[%d] = %d\n",i, vec->size);*/
		printf("<\n");
		i++;
	}
}

void	valid_instr(char *instr, int off, t_vector	*instrs)
{
	int	i;
	int	endi;

	if(instrs == NULL)
			instrs = ft_vecnew();

	i = off - 1;
	if (off == 0 || off == 5 || off == 8)
		endi = off + 3;
	else
		endi = off + 2;
	while (++i < endi)
	{
		if (ft_strcmp(instr, g_avinstrs[i]) == 0)
		{
			ft_vecadd(instrs, ft_strdup(instr));

			printf("instruction[%d] = %s\n", instrs->count, (char*)instrs->data[instrs->count - 1]);
			return ;
		}
		printf("count = [%d]\n", instrs->count);
		//printf("instruction[%d] = %s\n", instrs->count, (char*)instrs->data[instrs->count - 1]);
	}
	error();
	ft_vecdel(instrs, instrs->size);
	exit(0);
}

int get_offset(char	*instr)
{
	if (instr[0] == 's' && ft_strlen(instr) == 2)
		return (0);
	else if (instr[0] == 'p' && ft_strlen(instr) == 2)
		return (3);
	else if (instr[0] == 'r' && ft_strlen(instr) == 2)
		return (5);
	else if (instr[0] == 'r' && ft_strlen(instr) == 3)
		return (8);
	else
		return (-1);
}



void	read_instructions(t_vector	**instrs)
{
	char	*instr;
	int		n;
	int		off;
	int		cmd_type;

	instr = NULL;
	while ((n = get_next_line(0, &instr)) > 0)
	{
		printf("__%s__", instr);
		if (ft_strlen(instr) == 0)
			break ;
		if (!(cmd_type = check_intruction(instr)))
			error();
		printf(".%d\n", cmd_type);
		valid_instr(instr, get_offset(instr),*instrs);

		free (instr);
		instr = NULL;
	}
	free (instr);
	printf("end_read\n");
	int i = 0;
	//printf("count = %d\n", instrs->count);
	/*while (i < instrs->count)
	{
		printf("instruction[%d] = %s\n", i, (char*)instrs->data[i]);
		i++;
	}*/
	//vec_print(instrs);
	return ;
}

