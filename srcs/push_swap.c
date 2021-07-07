#include "push_swap.h"

#include "stack.h"
#include "logging.h"

void	b_to_a(t_list **cmd, t_stack *sta, t_stack *stb, int range);

int	cmp(int *a, int *b)
{
	return (*a - *b);
}

void	print_num(void *num)
{
	ft_putnbr_fd(*(int *)num, 2);
	ft_putstr_fd(" ", 2);
}

void put_stack(t_stack *sta, t_stack *stb)
{
	// if (1)
	// 	return;
	ft_putstr_fd(CYAN"sta: ", 2);
	ft_lstiter(sta->top, print_num);
	ft_putendl_fd("", 2);
	ft_putstr_fd("stb: ", 2);
	ft_lstiter(stb->top, print_num);
	ft_putendl_fd("\n---"END, 2);
}

int	get_pivot(t_stack *stack, int range)
{
	t_list	*sorted;
	t_list	*median_elem;
	int		median;

	sorted = ft_lstndup(stack->top, range);
	ft_lst_sort(&sorted, cmp);
	median_elem = ft_lst_at(sorted, range / 2 + range % 2 - 1);
	median = *(int *)median_elem->content;
	ft_lstclear(&sorted, free);
	return (median);
}

void	a_to_b(t_list **cmd, t_stack *sta, t_stack *stb, int range)
{
	int	pivot;
	int	ra;
	int	pb;

	if (range == 1)
		return ;
	pivot = get_pivot(sta, range);
	ra = 0;
	pb = 0;
	while (range--)
	{
		if (*(int *)sta->top->content > pivot)
		{
			st_rotate(cmd, sta);
			ra++;
		}
		else
		{
			st_push(cmd, stb, sta);
			pb++;
		}
	}
	range = 0;
	while (range++ < ra)
		st_rrotate(cmd, sta);
	put_stack(sta, stb);
	a_to_b(cmd, sta, stb, ra);
	b_to_a(cmd, sta, stb, pb);
}

void	b_to_a(t_list **cmd, t_stack *sta, t_stack *stb, int range)
{
	int	pivot;
	int	rb;
	int	pa;

	if (range == 1)
	{
		st_push(cmd, sta, stb);
		return ;
	}
	pivot = get_pivot(stb, range);
	rb = 0;
	pa = 0;
	while (range--)
	{
		if (*(int *)stb->top->content > pivot)
		{
			st_push(cmd, sta, stb);
			pa++;
		}
		else
		{
			st_rotate(cmd, stb);
			rb++;
		}
	}
	range = 0;
	while (range++ < rb)
		st_rrotate(cmd, stb);
	put_stack(sta, stb);
	a_to_b(cmd, sta, stb, pa);
	b_to_a(cmd, sta, stb, rb);
}

void	push_swap(t_list **cmd, t_stack *sta, t_stack *stb)
{
	if (sta->len == 2)
		if (*(int *)sta->top->content > *(int *)sta->top->next->content)
			st_swap(cmd, sta);
	if (sta->len > 2)
	{
		a_to_b(cmd, sta, stb, sta->len);
	}
	return ;
}
