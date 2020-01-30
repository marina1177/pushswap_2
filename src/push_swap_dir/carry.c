#include "../../includes/push_swap.h"

void	sortcarry(int *sta, int n)
{
	int	*max;
	int	*min;
	int	i;

	//print_st(sta);
	i = sta[0];
	min = &(sta[i]);
	max = &(sta[i]);

	while(i <= n + sta[0] - 1)
	{
		if(sta[i] > *max)
			max = &(sta[i]);
		if(sta[i] < *min)
			min = &(sta[i]);
		i++;
	}
	/*printf("min = %d___max = %d\n", *min,  *max);
	printf("max - min = %ld\n", (max - min));*/
	if((max - min) == 1 && n > 2)
	{
		if((min - &(sta[sta[0]])) > 0)
		{
			//printf("1_1\n");
			swap_stack(sta);
			print_op("sa\n");//print_st(sta);
		}
		else if((min - &(sta[sta[0]])) == 0)
		{
			//printf("1_2\n");
			rot_stack(sta);
			print_op("ra\n");//print_st(sta);
			swap_stack(sta);
			print_op("sa\n");//print_st(sta);
			revrot_stack(sta);
			print_op("rra\n");//print_st(sta);
		}
	}
	else if ((max - min) == -1 && n > 2)
	{
		if((max - &(sta[sta[0]])) > 0)
		{
			//printf("2_1\n");
			revrot_stack(sta);
			print_op("rra\n");//print_st(sta);
		}
		else if((max - &(sta[sta[0]])) == 0)
		{
			//printf("2_2\n");
			rot_stack(sta);
			print_op("ra\n");//print_st(sta);
		}
	}
	else if ((max - min) == -1 && n == 2)
	{
		//printf("3_\n");
		swap_stack(sta);
		print_op("sa\n");//print_st(sta);
	}
	else if ((max - min) == -2 && n > 2)
	{
		//printf("4_\n");
		rot_stack(sta);
		print_op("ra\n");//print_st(sta);
		swap_stack(sta);
		print_op("sa\n");//print_st(sta);
	}
	else if ((max - min) == 2 && n > 2)
	{
		//printf("5_\n");
		return ;
	}
	return ;
}


void	pushcarry(int *sta, int *stb, int n)
{
	int	*max;
	int	*min;
	int	i;

	i = stb[0];
	min = &(stb[i]);
	max = &(stb[i]);

	while(i <= n + stb[0] - 1)
	{
		if(stb[i] > *max)
			max = &(stb[i]);
		if(stb[i] < *min)
			min = &(stb[i]);
		i++;
	}
	//printf("min = %d___max = %d\n", *min,  *max);

	if(stb[stb[0]] == *min)
	{
		swap_stack(stb);
		print_op("sb\n");//print_st(sta);
	}
	push_stack(sta, stb);
	print_op("pa\n");//print_st(sta);
	if (n == 3)
	{
		if (stb[stb[0]] < stb[stb[0] + 1])
		{
			swap_stack(stb);
			print_op("sb\n");//print_st(sta);
		}
		push_stack(sta, stb);
		print_op("pa\n");//print_st(sta);
		if (sta[sta[0]] > sta[sta[0] + 1])
		{
			swap_stack(sta);
			print_op("sa\n");//print_st(sta);
		}
	}
	push_stack(sta, stb);
	print_op("pa\n");//print_st(sta);
}

void	parse_carry_a(int *sta, int n)
{
	int	*max;
	int	*min;
	int	i;

	i = sta[0];
	min = &(sta[i]);
	max = &(sta[i]);

	while (i <= n + sta[0] - 1)
	{
		if (sta[i] > *max)
			max = &(sta[i]);
		if (sta[i] < *min)
			min = &(sta[i]);
		i++;
	}
	//printf("min = %d___max = %d\n", *min,  *max);
	if ((max - min) == 1 && n > 2)
	{
		if (min == &(sta[sta[0]]))
		{
			//printf("1_1\n");
			rot_stack(sta);
			print_op("ra\n");//print_st(sta);

			swap_stack(sta);
			print_op("sa\n");//print_st(sta);

			revrot_stack(sta);
			print_op("rra\n");//print_st(sta);
		}
		else if ((min - &(sta[sta[0]])) > 0)
		{
			//printf("1_2\n");
			swap_stack(sta);
			print_op("sa\n");//print_st(sta);
		}
	}
	else if ((max - min) == -1 && n > 2)
	{
		if ((max - &(sta[sta[0]])) > 0)
		{
			//printf("2_1\n");
			rot_stack(sta);
			print_op("ra\n");//print_st(sta);

			swap_stack(sta);
			print_op("sa\n");//print_st(sta);

			revrot_stack(sta);
			print_op("rra\n");//print_st(sta);

			swap_stack(sta);
			print_op("sa\n");//print_st(sta);
		}
		else if ((max - &(sta[sta[0]])) == 0)
		{
			//printf("2_2\n");

			swap_stack(sta);
			print_op("sa\n");//print_st(sta);

			rot_stack(sta);
			print_op("ra\n");//print_st(sta);

			swap_stack(sta);
			print_op("sa\n");//print_st(sta);

			revrot_stack(sta);
			print_op("rra\n");//print_st(sta);
		}
	}
	else if ((max - min) == -1 && n == 2)
	{
		//printf("3_\n");
		swap_stack(sta);
		print_op("sa\n");//print_st(sta);
	}
	else if ((max - min) == -2 && n > 2)
	{
		//printf("4_\n");

		swap_stack(sta);
		print_op("sa\n");//print_st(sta);

		rot_stack(sta);
		print_op("ra\n");//print_st(sta);

		swap_stack(sta);
		print_op("sa\n");//print_st(sta);

		revrot_stack(sta);
		print_op("rra\n");//print_st(sta);

		swap_stack(sta);
		print_op("sa\n");//print_st(sta);
	}
	else if ((max - min) == 2 && n > 2)
	{
		//printf("5_\n");
		return ;
	}
	return ;
}

int		check_bottom_b(int *stb, int rem, int median)
{
	int		i;
	int		cnt;

	/*printf("stb[0] = %d\n", stb[0]);
	printf("rem = %d\n", rem);
	printf("stb[0] + rem - 1= %d\n", stb[0] + rem -1);*/

	i = stb[0] + 1;
	cnt = 0;
	while (i <= stb[0] + rem - 1)
	{
		if (stb[i] >= median)
		{
			cnt++;
		}
		i++;
	}
	//printf("cnt = %d\n", cnt);
	return (cnt);
}
