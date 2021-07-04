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

void	st_push(t_list **cmd, t_stack *dst, t_stack *src)
{
	t_list	*tmp;

	if (*src->top == NULL)
		return ;
	tmp = (*src->top)->next;
	(*src->top)->next = NULL;
	ft_lstadd_front(dst->top, *src->top);
	*src->top = tmp;
	src->len--;
	dst->len++;
	add_cmd(cmd, "p", dst->name);
}

void	st_rotate(t_list **cmd, t_stack *stack)
{
	t_list	*tmp;

	if (*stack->top == NULL || (*stack->top)->next == NULL)
		return ;
	tmp = *stack->top;
	*stack->top = (*stack->top)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack->top, tmp);
	add_cmd(cmd, "r", stack->name);
}
