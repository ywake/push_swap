#include "stack.h"

#include "error.h"

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
	t_list	*tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top;
	if (tmp->next == stack->btm)
		stack->btm = tmp;
	stack->top = stack->top->next;
	tmp->next = stack->top->next;
	stack->top->next = tmp;
	if (cmd)
		add_cmd(cmd, "s", stack->name);
}

void	st_push(t_list **cmd, t_stack *dst, t_stack *src)
{
	t_list	*tmp;

	if (src->top == NULL)
		return ;
	tmp = src->top;
	src->top = tmp->next;
	if (src->top == NULL)
		src->btm = NULL;
	tmp->next = NULL;
	ft_lstadd_front(&dst->top, tmp);
	if (dst->btm == NULL)
		dst->btm = tmp;
	src->len--;
	dst->len++;
	if (cmd)
		add_cmd(cmd, "p", dst->name);
}

void	st_rotate(t_list **cmd, t_stack *stack)
{
	t_list	*tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = NULL;
	stack->btm->next = tmp;
	stack->btm = tmp;
	if (cmd)
		add_cmd(cmd, "r", stack->name);
}

void	st_rrotate(t_list **cmd, t_stack *stack)
{
	t_list	*last2;

	if (stack->top == NULL || (stack->top)->next == NULL)
		return ;
	last2 = ft_lst_at(stack->top, stack->len - 2);
	last2->next = NULL;
	ft_lstadd_front(&stack->top, stack->btm);
	stack->btm = last2;
	if (cmd)
		add_cmd(cmd, "rr", stack->name);
}
