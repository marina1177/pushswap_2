#include "../../includes/push_swap.h"

void	rot_stack(int *st)
{
	int	i;
	int	tmp;
	int	size;

	size = g_members - 1;
	i = st[0];
	tmp = st[i];
	while (i <= size)
	{
		st[i] = st[i+1];
		i++;
	}
	st[g_members] = tmp;

}
void	rot_stacks(int *st1, int *st2)
{
	rot_stack(st1);
	rot_stack(st2);
}

void	revrot_stack(int *st)
{
	int	i;
	int	tmp;
	int	size;

	size = g_members;
	tmp = st[size];
	while ( size > st[0] )
	{
		st[size] = st[size-1];
		size--;
	}
	st[st[0]] = tmp;
}

void	revrot_stacks(int *st1, int *st2)
{
	revrot_stack(st1);
	revrot_stack(st2);
}
