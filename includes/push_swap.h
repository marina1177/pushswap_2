/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:52:10 by bcharity          #+#    #+#             */
/*   Updated: 2020/01/16 20:52:10 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>


# include <stdio.h>

typedef struct s_mlst	t_mlst;

struct		s_mlst
{
	int		num;
	t_mlst	*prev;
	t_mlst	*next;
};

/////////////////////COMMON//////////////////////////

// common_1.c
void	check_repeat(int *st, int val);
void	check_arg(int *sta, char **curr, int *len);
int		fill_sta(int ac, char **av, int *sta);
void	init_stacks(int argc, char *argv[], int **sta, int **stb);


// functions.c
void	swap_stack(int *st);
void	swap_stacks(int *st1, int *st2);
void	push_stack(int *st1, int *st2);

// rot_functions.c
void	rot_stack(int *st);
void	rot_stacks(int *st1, int *st2);
void	revrot_stack(int *st);
void	revrot_stacks(int *st1, int *st2);
void	print_op(char *op);
void	print_st(int *st);

/////////////////PUSH SWAP//////////////////////////
// main.c
int		ordered(int *s);
void	rotate(int *s, int len, int min);
void	error();

// median.c
int		get_m(int *st, int n);
int		sel_m(int *a, int i, int n);
void	insertion_sort(int *a, int n);
int		partition(int *a, int n, int x);

// divide_sta.c
int		devide_a(int **sta, int **stb, int m);
int		split_a_mdn0(int **sta, int **stb);
void	parse_b(int *sta, int *stb, int *num_b);
void	parse_a(int *sta, int *stb, int *num_b, int count_a);

// carry.c
void	sortcarry(int *sta, int n);
void	pushcarry(int *sta, int *stb, int n);
void	parse_carry_a(int *sta, int n);
int		check_bottom_b(int *stb, int rem, int median);

////////////////////////CHECKER////////////////////////

/*
**checker.c
*/
int		check_intruction(const char *cmd);
void	result(t_mlst *cmds, int *sta, int *stb);
void	answer(int var);

int		read_i(t_mlst *cmds);
void	add_next(t_mlst **curr);


int							g_members;

#endif

