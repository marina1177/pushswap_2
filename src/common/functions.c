#include "../../includes/push_swap.h"

void	swap_stack(int *st)
{
	int	tmp;
	int	a;
	int	b;

	if (st[0] == g_members)
		return ;
	a = st[st[0]];
	b = st[st[0] + 1];
	tmp = a;
	st[st[0]] = b;
	st[st[0] + 1] = tmp;
}

void	swap_stacks(int *st1, int *st2)
{
	swap_stack(st1);
	swap_stack(st2);
}

void	push_stack(int *st1, int *st2)
{
	int	tmp;

	if (st2[0] == g_members + 1 || st1[0] == 1)
		return ;
	tmp = st2[st2[0]];
	st2[0]++;
	st1[0]--;
	st1[st1[0]] = tmp;
}

void	print_op(char *op)
{
	write(1, op, ft_strlen(op));
}

void	print_st(int *st)
{
  int	size;

  printf("printst_");
  for (int i = st[0]; i <= g_members; i++)
    printf("_%d_", st[i]);
  printf("\n");
}
