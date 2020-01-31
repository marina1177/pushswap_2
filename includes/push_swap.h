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

/*
*************************COMMON************************
*******************************************************
*/

/*
** common_1.c
*/
size_t		count_word(char const *s, char c);
void		check_repeat(int *st, int val);
int			calc_members(int ac, char **av);
void		check_arg(int *sta, char **curr, int *len);
int			fill_sta(int ac, char **av, int *sta);
void		init_stacks(int argc, char *argv[], int **sta, int **stb);

/*
** functions.c
*/
void		swap_stack(int *st);
void		swap_stacks(int *st1, int *st2);
void		push_stack(int *st1, int *st2);

/*
** rot_functions.c
*/
void		rot_stack(int *st);
void		rot_stacks(int *st1, int *st2);
void		revrot_stack(int *st);
void		revrot_stacks(int *st1, int *st2);
void		print_op(char *op);
void		print_st(int *st);


/*
************************PUSH SWAP**********************
*******************************************************
*/

/*
** main.c
*/
int			ordered(int *s);
void		rotate(int *s, int len, int min);
void		error();

/*
** median_1.c
*/
int			get_m(int *st, int n);
int			sel_m_2(int *a, int n, int *var);
int			sel_m(int *a, int i, int n);

/*
** median_2.c
*/
void		insertion_sort(int *a, int n);
int			partition_2(int *a, int n, int x);
int			partition(int *a, int n, int x);

/*
** sorting_1.c
*/
int			devide_a(int **sta, int **stb, int m);
int			begin_pyramid(int **sta, int **stb, int *arr);
int			sorting(int **sta, int **stb);

/*
** sorting_2.c
*/
int			separate_a(int *sta,int *stb, int *num_b, int *num_a);
void		parse_a(int *sta, int *stb, int *num_b, int count_a);
void		put_back_b(int *stb, int *num_b, int cnt_b);
void		separate_b(int *sta,int *stb, int *num_b, int cnt[2]);
void		parse_b(int *sta, int *stb, int *num_b);


/*
** carry.c
*/
void		sortcarry_a(int *sta, int n);
void		pushcarry(int *sta, int *stb, int n);
void		parse_carry_a(int *sta, int n);

int			check_bottom_b(int *stb, int rem, int median);
int			check_bottom_a(int *sta, int rem, int median);

/*
*************************CHECKER***********************
*******************************************************
*/

/*
** checker.c
*/
int			check_intruction(const char *cmd);
void		result(t_mlst *cmds, int *sta, int *stb);
void		answer(int var);

int			read_i(t_mlst *cmds);
void		add_next(t_mlst **curr);


int			g_members;

#endif

