#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stack
{
	char	*name;
	int		len;
	t_list	**top;
}	t_stack;

t_stack	*new_stack(t_list *list);
void	st_swap(t_list **cmd, t_stack *stack);
void	st_push(t_list **cmd, t_stack *dst, t_stack *src);

#endif
