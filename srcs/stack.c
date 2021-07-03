#include "stack.h"

#include "error.h"

t_stack	*new_stack(t_list *list)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack *));
	if (stack == NULL)
		error();
	stack->top = &list;
	// stack->bottom = &(ft_lstlast(list));
	return (stack);
}

void	add_cmd(t_list **cmd, char *str, char *stack_name)
{
	char	*join;
	t_list	*n;

	join = ft_strjoin(str, stack_name);
	n = ft_lstnew(join);
	if (join == NULL || n == NULL)
		error();
	ft_lstadd_front(cmd, n);
}

void	st_swap(t_list **cmd, t_stack *stack)
{
	int		*tmp;

	if (*stack->top == NULL || (*stack->top)->next == NULL)
		return ;
	tmp = (int *)(*stack->top)->content;
	(*stack->top)->content = (int *)(*stack->top)->next->content;
	(*stack->top)->next->content = tmp;
	add_cmd(cmd, "s", stack->name);
}
