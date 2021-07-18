#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

enum e_stacks
{
	st_a,
	st_b,
	st_len,
};

void	optimize(t_list **cmd);
void	rm_nonsense(t_list **cmd);
void	push_swap_a(t_list **cmd, t_stack *sta, t_stack *stb, int range);
void	push_swap_b(t_list **cmd, t_stack *sta, t_stack *stb, int range);
void	small_swap(t_list **cmd, t_stack *st[st_len],
			int range, enum e_stacks ope);

#endif
