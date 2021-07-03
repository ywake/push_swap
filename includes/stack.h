#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stack
{
	char	*name;
	t_list	**top;
	t_list	**bottom;
}	t_stack;

t_stack	*new_stack(t_list *list);
void	st_swap(t_list **cmd, t_stack *stack);

#endif
