#ifndef CHEKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <float.h>
# include <string.h>

# include <stdio.h>

typedef unsigned char	t_1b;
typedef unsigned short	t_2b;



# define SWAP_A		(t_1b)0b100
# define SWAP_B		(t_1b)0b010
# define SWAP_AB	(t_1b)0b001

# define PUSH_A		(t_1b)0b10
# define PUSH_B		(t_1b)0b01

# define ROT_A		(t_1b)0b100
# define ROT_B		(t_1b)0b010
# define ROT_AB		(t_1b)0b001

# define REVROT_A		(t_1b)0b100
# define REVROT_B		(t_1b)0b010
# define REVROT_AB		(t_1b)0b001



typedef struct s_mlst	t_mlst;

struct		s_mlst
{
	int		num;
	t_mlst	*next;
};

/*
**checker.c
*/
int			check_intruction(const char *cmd);
void		result(t_vector	*instrs, int *sta, int *stb);
void		answer(_Bool var);


void	valid_instr(char *instr, int off, t_vector	*instrs);
int 		get_offset(char	*instr);
void	read_instructions(t_vector	*instrs);


int			read_i(t_list *cmds)


#endif
