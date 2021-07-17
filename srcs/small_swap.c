#include "push_swap.h"

#include "libft.h"
#include "stack.h"
#include "data.h"
#include "debug.h"

void	small_swap_a_len3(t_list **cmd, t_stack *st[st_len], int val[3])
{
	if (val[0] < val[1] && val[0] < val[2] && val[1] > val[2])
	{
		st_rrotate(cmd, st[st_a]);
		st_swap(cmd, st[st_a]);
	}
	else if (val[1] < val[0] && val[1] < val[2])
	{
		if (val[0] < val[2])
			return (st_swap(cmd, st[st_a]));
		st_rotate(cmd, st[st_a]);
	}
	else if (val[2] < val[0] && val[2] < val[1])
	{
		if (val[0] > val[1])
			st_swap(cmd, st[st_a]);
		st_rrotate(cmd, st[st_a]);
	}
}

/**
 * 3 2 1 -> 2 3 1
 * X 1 Y -> 1 X Y
 */
void	small_swap_a(t_list **cmd, t_stack *st[st_len], int r, int val[3])
{
	if (st[st_a]->len == 3)
		return (small_swap_a_len3(cmd, st, val));
	if (val[2] < val[0] && val[2] < val[1])
	{
		if (val[0] > val[1])
			st_swap(cmd, st[st_a]);
		st_rotate(cmd, st[st_a]);
		st_swap(cmd, st[st_a]);
		st_rrotate(cmd, st[st_a]);
		st_swap(cmd, st[st_a]);
	}
	else if (val[1] < val[0] && val[1] < val[2])
	{
		st_swap(cmd, st[st_a]);
		return (small_swap(cmd, st, r, st_a));
	}
	else if (val[1] > val[2])
	{
		st_rotate(cmd, st[st_a]);
		st_swap(cmd, st[st_a]);
		st_rrotate(cmd, st[st_a]);
	}
}

/**
 * 1 2 3 -> 2 1 3
 * X 3 Y -> 3 X Y
 */
void	small_swap_b(t_list **cmd, t_stack *st[st_len], int r, int val[3])
{
	if (val[2] > val[0] && val[2] > val[1])
	{
		if (val[0] < val[1])
			st_swap(cmd, st[st_b]);
		st_push(cmd, st[st_a], st[st_b]);
		st_swap(cmd, st[st_b]);
		st_push(cmd, st[st_a], st[st_b]);
		st_swap(cmd, st[st_a]);
		return (st_push(cmd, st[st_a], st[st_b]));
	}
	else if (val[1] > val[0] && val[1] > val[2])
	{
		st_swap(cmd, st[st_b]);
		return (small_swap(cmd, st, r, st_b));
	}
	else if (val[1] < val[2])
	{
		st_push(cmd, st[st_a], st[st_b]);
		r--;
		st_swap(cmd, st[st_b]);
	}
	while (r--)
		st_push(cmd, st[st_a], st[st_b]);
}

void	small_swap(t_list **cmd, t_stack *st[st_len], int r, enum e_stacks ope)
{
	int	val[3];

	if (r == 2 && ope == st_a)
		if (get_value(st[st_a]->top) > get_value(st[st_a]->top->next))
			st_swap(cmd, st[st_a]);
	if (r == 2 && ope == st_b)
		if (get_value(st[st_b]->top) < get_value(st[st_b]->top->next))
			st_swap(cmd, st[st_b]);
	if (r < 3)
	{
		while (ope == st_b && r--)
			st_push(cmd, st[st_a], st[st_b]);
		return ;
	}
	val[0] = get_value(st[ope]->top);
	val[1] = get_value(st[ope]->top->next);
	val[2] = get_value(st[ope]->top->next->next);
	if (ope == st_a)
		small_swap_a(cmd, st, r, val);
	else
		small_swap_b(cmd, st, r, val);
}
