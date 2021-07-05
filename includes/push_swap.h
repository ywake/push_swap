#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

t_list	*make_data(int argc, char *argv[]);
void	push_swap(t_list **cmd, t_stack *sta, t_stack *stb);
void	print_num(void *num);

#endif
