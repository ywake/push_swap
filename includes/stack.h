#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stack
{
	char	*name;
	int		len;
	t_list	*top;
}	t_stack;

void	st_swap(t_list **cmd, t_stack *stack);
void	st_push(t_list **cmd, t_stack *dst, t_stack *src);
void	st_rotate(t_list **cmd, t_stack *stack);
void	st_rrotate(t_list **cmd, t_stack *stack);

#endif
