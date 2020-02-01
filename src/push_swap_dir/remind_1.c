#include "../../includes/push_swap.h"


void	sortrem_op1(int *sta, int **extr)
{
	if((extr[0] - &(sta[sta[0]])) > 0)
		{
			swap_stack(sta);
			print_op("sa\n");
		}
		else if((extr[0] - &(sta[sta[0]])) == 0)
		{
			rot_stack(sta);
			print_op("ra\n");
			swap_stack(sta);
			print_op("sa\n");
			revrot_stack(sta);
			print_op("rra\n");
		}
}

void	sortrem_op2(int *sta, int **extr)
{
	if((extr[1] - &(sta[sta[0]])) > 0)
		{
			revrot_stack(sta);
			print_op("rra\n");
		}
		else if((extr[1] - &(sta[sta[0]])) == 0)
		{
			rot_stack(sta);
			print_op("ra\n");
		}
}

void	sortrem_a(int *sta, int n)
{
	int	*extr[2];

	extrem_pnt(sta, n, &((extr)[0]));
	if((extr[1] - extr[0]) == 1 && n > 2)
		sortrem_op1(sta, &((extr)[0]));
	else if ((extr[1] - extr[0]) == -1 && n > 2)
		sortrem_op2(sta, &((extr)[0]));
	else if ((extr[1] - extr[0]) == -1 && n == 2)
	{
		swap_stack(sta);
		print_op("sa\n");
	}
	else if ((extr[1] - extr[0]) == -2 && n > 2)
	{
		rot_stack(sta);
		print_op("ra\n");
		swap_stack(sta);
		print_op("sa\n");
	}
	else if ((extr[1] - extr[0]) == 2 && n > 2)
		return ;
	return ;
}

void	pushcarry_op(int *sta, int *stb)
{
	if (stb[stb[0]] < stb[stb[0] + 1])
		{
			swap_stack(stb);
			print_op("sb\n");
		}
		push_stack(sta, stb);
		print_op("pa\n");
		if (sta[sta[0]] > sta[sta[0] + 1])
		{
			swap_stack(sta);
			print_op("sa\n");
		}
}

void	pushcarry(int *sta, int *stb, int n)
{
	int	*extr[2];

	extrem_pnt(sta, n, &((extr)[0]));
	if(stb[stb[0]] == *(extr[0]))
	{
		swap_stack(stb);
		print_op("sb\n");
	}
	push_stack(sta, stb);
	print_op("pa\n");
	if (n == 3)
		pushcarry_op(sta, stb);
	push_stack(sta, stb);
	print_op("pa\n");
	return ;
}

