/*# include <unistd.h>
# include <stdarg.h>
//# include "../../libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <float.h>
# include <string.h>

# include <stdio.h>

int		sel(int *a, int i, int n);
void	insertion_sort(int *a, int n);
int		partition(int *a, int n, int x);*/
#include "../../includes/push_swap.h"

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _b : _a; })


/*int main(int argc, char *argv[])
{
  int *a;
  int n = argc - 1;

  a = malloc(sizeof(int)*n);

  for(int i = 0; i < n; i++) {
	// Parse each string into a number for the array entry
	a[i] = atoi(argv[i+1]);
	printf("%d ", a[i]);
  }
  printf("\n");

  int i = n/2;
  int elem = sel(a, i, n);
  printf("%d is element %d from %d", elem, i, n);

  free(a);

  return 0;
}*/
int	get_m(int *st, int n)
{
	int	*tmp;//[n - st[0] + 1];
	int	size;

	size = n - st[0] + 1;
  tmp = ft_memalloc(size*sizeof(int));
	ft_memcpy(tmp, &(st[st[0]]), size*sizeof(int));
	return (sel_m(tmp, size / 2, size));
}

int		sel_m(int *a, int i, int n)
{
	int	n_meds;
	int	j;
	int	l;
	int	tmp;
	int median_of_medians;
	int k;

	if(n == 1)
	{
		return a[0];
	}
	n_meds = 0;
	j = 0;
	while (j < n)
	{
		l = min(5, n - j);
		insertion_sort(a + j, l);
		tmp = a[j/5];
		a[j/5] = a[j + l/2];
		a[j + l/2] = tmp;
		n_meds++;
		 j += 5;
	}
	if(n_meds > 1)
	{
		median_of_medians = sel_m(a, n_meds/2, n_meds);
	}
	else
	{
		median_of_medians = a[0];
	}

	k = partition(a, n, median_of_medians);

	if(k == i)
	{
		return median_of_medians;
	}
	else if (i < k)
	{
		return sel_m(a, i, k);
	}
	else
	{
		return sel_m(a + k, i - k, n - k);
	}
}


void insertion_sort(int *a, int n)
// Insertion sort array a of length n
{
  for(int j = 1; j < n; j++) {
	int key = a[j];
	// insert a[j] in the correct position a[0...(j-1)]
	int i = j - 1;
	while ((i >= 0) && (a[i] > key)) {
	  a[i + 1] = a[i];
	  i--;
	}
	a[i+1] = key;
  }
}


int partition(int *a, int n, int x)
// Partition array a of length n around x;
// Return the number of elements to the left of the pivot.
{
  // First find the pivot and place at the end
  for(int i = 0; i < n; i++) {
	if(a[i] == x) {
	  a[i] = a[n-1];
	  a[n-1] = x;
    }
  }

  int i = 0;
  for(int j = 0; j < (n-1); j++) {
	if(a[j] <= x) {
	  int tmp = a[j];
	  a[j] = a[i];
	  a[i] = tmp;
	  i++;
	}
  }

  // Place the pivot in the correct position
  a[n-1] = a[i];
  a[i] = x;

  return i;
}
