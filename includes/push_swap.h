/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:45:07 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/02 14:36:34 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct		s_mlst
{
	int				num;
	struct s_mlst	*next;
	struct s_mlst	*prev;
}					t_mlst;

/*
*************************COMMON************************
*******************************************************
*/

/*
** common_1.c
*/
void				check_repeat(int *st, int val);
int					calc_members(int ac, char **av);
void				check_arg(int *sta, char **curr, int *len);
int					fill_sta(int ac, char **av, int *sta);
void				init_stacks(int argc, char *argv[], int **sta, int **stb);

/*
** common_2.c
*/
size_t				count_word(char const *s, char c);
void				add_next(t_mlst **curr);
void				answer(int var);
void				error();

/*
** functions.c
*/
void				swap_stack(int *st);
void				swap_stacks(int *st1, int *st2);
void				push_stack(int *st1, int *st2);

/*
** rot_functions.c
*/
void				rot_stack(int *st);
void				rot_stacks(int *st1, int *st2);
void				revrot_stack(int *st);
void				revrot_stacks(int *st1, int *st2);
void				print_op(char *op);

/*
************************PUSH SWAP**********************
*******************************************************
*/

/*
** main.c
*/
int					ordered(int *s);
void				rotate(int *s, int len, int min);
void				print_st(int *st);

/*
** median_1.c
*/
int					fun_min(int a, int b);
int					get_m(int *st, int n);
void				sel_m_2(int *a, int n, int *var);
int					sel_m(int *a, int i, int n);

/*
** median_2.c
*/
void				insertion_sort(int *a, int n);
int					partition_2(int *a, int n, int x);
int					partition(int *a, int n, int x);

/*
** sorting_1.c
*/
int					devide_a(int **sta, int **stb, int m);
int					begin_pyramid(int **sta, int **stb, int *arr);
int					sorting(int **sta, int **stb);
int					check_bottom_b(int *stb, int rem, int median);
int					check_bottom_a(int *sta, int rem, int median);

/*
** sorting_2.c
*/
int					separate_a(int *sta, int *stb, int *num_b, int *num_a);
void				parse_a(int *sta, int *stb, int *num_b, int count_a);
void				put_back_b(int *stb, int *num_b, int cnt_b);
void				separate_b(int *sta, int *stb, int *num_b, int cnt[2]);
void				parse_b(int *sta, int *stb, int *num_b);

/*
** remind_1.c
*/
void				sortrem_op2(int *sta, int **extr);
void				sortrem_op1(int *sta, int **extr);
void				sortrem_a(int *sta, int n);
void				pushcarry_op(int *sta, int *stb);
void				pushcarry(int *sta, int *stb, int n);

/*
** remind_2.c
*/
void				extrem_pnt(int *st, int n, int **extr);
void				parsecarry_op3(int *sta, int **extr);
void				parsecarry_op2(int *sta, int **extr);
void				parsecarry_op1(int *sta, int **extr);
void				parse_carry_a(int *sta, int n);

/*
*************************CHECKER***********************
*******************************************************
*/

/*
** checker.c
*/
int					check_intruction(const char *cmd);
void				result(t_mlst *cmds, int *sta, int *stb);
void				get_answer(int *sta, int *stb);
int					read_i(t_mlst *cmds);

int					g_members;

#endif
