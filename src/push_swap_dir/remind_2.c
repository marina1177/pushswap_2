#include "../../includes/push_swap.h"

void	extrem_pnt(int *st, int n, int **extr)
{
	int	i;
	int	*max;
	int	*min;

	i = st[0];
	min = &(st[i]);
	max = &(st[i]);
	while(i <= n + st[0] - 1)
	{
		if(st[i] > *max)
			max = &(st[i]);
		if(st[i] < *min)
			min = &(st[i]);
		i++;
	}
	extr[0] = min;
	extr[1] = max;
}

void	parsecarry_op3(int *sta, int **extr)
{
	swap_stack(sta);
	print_op("sa\n");
	rot_stack(sta);
	print_op("ra\n");
	swap_stack(sta);
	print_op("sa\n");
	revrot_stack(sta);
	print_op("rra\n");
	swap_stack(sta);
	print_op("sa\n");
}

void	parsecarry_op2(int *sta, int **extr)
{
	if ((extr[1] - &(sta[sta[0]])) > 0)
		{
			rot_stack(sta);
			print_op("ra\n");
			swap_stack(sta);
			print_op("sa\n");
			revrot_stack(sta);
			print_op("rra\n");
			swap_stack(sta);
			print_op("sa\n");
		}
		else if ((extr[1] - &(sta[sta[0]])) == 0)
		{
			swap_stack(sta);
			print_op("sa\n");
			rot_stack(sta);
			print_op("ra\n");
			swap_stack(sta);
			print_op("sa\n");
			revrot_stack(sta);
			print_op("rra\n");
		}
}

void	parsecarry_op1(int *sta, int **extr)
{
	if ( extr[0] == &(sta[sta[0]]))
		{
			rot_stack(sta);
			print_op("ra\n");
			swap_stack(sta);
			print_op("sa\n");
			revrot_stack(sta);
			print_op("rra\n");
		}
		else if (( extr[0] - &(sta[sta[0]])) > 0)
		{
			swap_stack(sta);
			print_op("sa\n");
		}
}

void	parse_carry_a(int *sta, int n)
{
	int	*extr[2];

	extrem_pnt(sta, n, &((extr)[0]));
	if ((extr[1] -  extr[0]) == 1 && n > 2)
		parsecarry_op1(sta, extr);
	else if ((extr[1] - extr[0]) == -1 && n > 2)
		parsecarry_op2(sta, extr);
	else if ((extr[1] - extr[0]) == -1 && n == 2)
	{
		swap_stack(sta);
		print_op("sa\n");
	}
	else if ((extr[1] - extr[0]) == -2 && n > 2)
		parsecarry_op3(sta, extr);
	else if ((extr[1] - extr[0]) == 2 && n > 2)
		return ;
	return ;
}



