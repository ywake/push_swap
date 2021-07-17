#include "push_swap.h"

#include "data.h"
#include "stack.h"
#include "debug.h"

void	merge_to_b(t_list **cmd, t_stack *sta, t_stack *stb);

void	head_swap(t_list **cmd, t_stack	*stack)
{
	((t_data *)stack->top->content)->is_start = false;
	if (stack->top->next && !is_start(stack->top->next) \
			&& get_value(stack->top) > get_value(stack->top->next))
		st_swap(cmd, stack);
}

void	merge_to_a(t_list **cmd, t_stack *sta, t_stack *stb)
{
	bool	started;

	if (!stb->top)
		return ;
	if (sta->top)
		head_swap(cmd, sta);
	head_swap(cmd, stb);
	started = false;
	while ((sta->top && !is_start(sta->top)) \
			|| (stb->top && !is_start(stb->top)))
	{
		if (sta->top == NULL || is_start(sta->top))
			st_push(cmd, sta, stb);
		else if (stb->top == NULL || is_start(stb->top))
			;
		else if (get_value(sta->top) > get_value(stb->top))
			st_push(cmd, sta, stb);
		if (started == false)
		{
			((t_data *)sta->top->content)->is_start = true;
			started = true;
		}
		st_rotate(cmd, sta);
	}
	merge_to_b(cmd, sta, stb);
}

void	merge_to_b(t_list **cmd, t_stack *sta, t_stack *stb)
{
	bool	started;

	if (!sta->top || !stb->top)
		return ;
	head_swap(cmd, sta);
	head_swap(cmd, stb);
	started = false;
	while ((sta->top && !is_start(sta->top)) \
			|| (stb->top && !is_start(stb->top)))
	{
		if (stb->top == NULL || is_start(stb->top))
			st_push(cmd, stb, sta);
		else if (sta->top == NULL || is_start(sta->top))
			;
		else if (get_value(sta->top) < get_value(stb->top))
			st_push(cmd, stb, sta);
		if (started == false)
		{
			((t_data *)stb->top->content)->is_start = true;
			started = true;
		}
		st_rotate(cmd, stb);
	}
	merge_to_a(cmd, sta, stb);
}

void	merge(t_list **cmd, t_stack *sta, t_stack *stb)
{
	int		i;
	t_list	*elem[2];

	while (sta->len - stb->len > 0)
		st_push(cmd, stb, sta);
	elem[0] = sta->top;
	elem[1] = stb->top;
	i = 0;
	while (elem[0] || elem[1])
	{
		if (i % 2 == 0 && elem[0])
			((t_data *)elem[0]->content)->is_start = true;
		if (elem[0])
			elem[0] = elem[0]->next;
		if (i % 2 == 0 && elem[1])
			((t_data *)elem[1]->content)->is_start = true;
		if (elem[1])
			elem[1] = elem[1]->next;
		i++;
	}
	merge_to_a(cmd, sta, stb);
	if (sta->top == NULL)
		merge_to_a(cmd, sta, stb);
}

void	push_swap(t_list **cmd, t_stack *sta, t_stack *stb)
{
	if (sta->len == 2)
		if (get_value(sta->top) > get_value(sta->top->next))
			st_swap(cmd, sta);
	if (sta->len > 2)
		merge(cmd, sta, stb);
	return ;
}
