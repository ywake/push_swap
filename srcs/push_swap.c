#include "push_swap.h"

#include "stack.h"

int	cmp(int *a, int *b)
{
	return (*a - *b);
}

void	print_num(void *num)
{
	ft_putnbr_fd(*(int *)num, 2);
	ft_putendl_fd("", 2);
}

int	get_pivot(t_stack *stack)
{
	t_list	*sorted;
	t_list	*median_elem;
	int		median;

	sorted = ft_lstndup(stack->top, -1);
	ft_lst_sort(&sorted, cmp);
	median_elem = ft_lst_at(sorted, stack->len / 2 + stack->len % 2 - 1);
	median = *(int *)median_elem->content;
	ft_lstclear(&sorted, free);
	return (median);
}

void	a_to_b(t_list **cmd, t_stack *sta, t_stack *stb, int range)
{
	int	pivot;

	pivot = get_pivot(sta);
	while (range--)
	{
		(void)stb;
		if (*(int *)sta->top->content > pivot)
			st_rotate(cmd, sta);
		else
			st_push(cmd, stb, sta);
	}
	ft_putendl_fd("sta", 2);
	ft_lstiter(sta->top, print_num);
	ft_putendl_fd("stb", 2);
	ft_lstiter(stb->top, print_num);
}

void	push_swap(t_list **cmd, t_stack *sta, t_stack *stb)
{
	if (sta->len == 2)
		if (*(int *)sta->top->content > *(int *)sta->top->next->content)
			st_swap(cmd, sta);
	if (sta->len > 2)
	{
		(void)stb;
		a_to_b(cmd, sta, stb, sta->len);
	}
	return ;
}
