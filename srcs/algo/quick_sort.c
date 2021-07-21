#include "push_swap.h"

#include "data.h"
#include "stack.h"
#include "debug.h"
#include "validation.h"

enum	e_pivot
{
	low,
	high,
	piv_len,
};

enum	e_count
{
	ra,
	pa,
	rb,
	pb,
	cnt_len,
};

void	init(t_stack *stack, int range, int piv[piv_len], int count[cnt_len])
{
	t_list	*sorted;
	int		i;

	sorted = ft_lstndup(stack->top, range);
	ft_lst_sort(&sorted, cmp);
	piv[low] = ((t_data *)ft_lst_at(sorted, range / 3)->content)->val;
	piv[high] = ((t_data *)ft_lst_at(sorted, range * 2 / 3)->content)->val;
	ft_lstclear(&sorted, free);
	i = 0;
	while (i < cnt_len)
	{
		count[i] = 0;
		i++;
	}
}

void	rewind(t_list **cmd, t_stack *sta, t_stack *stb, int count[cnt_len])
{
	int	i;

	i = 0;
	while (i < (int)ft_min(count[ra], count[rb]))
	{
		st_double(cmd, st_rrotate, sta, stb);
		i++;
	}
	while (i < count[ra])
	{
		st_rrotate(cmd, sta);
		i++;
	}
	while (i < count[rb])
	{
		st_rrotate(cmd, stb);
		i++;
	}
}

void	push_swap_a(t_list **cmd, t_stack *sta, t_stack *stb, int range)
{
	int	pivot[2];
	int	count[4];

	if (range <= 5)
		return (small_swap(cmd, (t_stack *[st_len]){sta, stb}, range, st_a));
	init(sta, range, pivot, count);
	while (range--)
	{
		if (get_value(sta->top) >= pivot[high] && ++count[ra])
			st_rotate(cmd, sta);
		else
		{
			st_push(cmd, stb, sta);
			count[pb]++;
			if (get_value(stb->top) >= pivot[low] && ++count[rb])
				st_rotate(cmd, stb);
		}
	}
	rewind(cmd, sta, stb, count);
	push_swap_a(cmd, sta, stb, count[ra]);
	push_swap_b(cmd, sta, stb, count[rb]);
	push_swap_b(cmd, sta, stb, count[pb] - count[rb]);
}

void	push_swap_b(t_list **cmd, t_stack *sta, t_stack *stb, int range)
{
	int	pivot[2];
	int	count[4];

	if (range <= 5)
		return (small_swap(cmd, (t_stack *[st_len]){sta, stb}, range, st_b));
	init(stb, range, pivot, count);
	while (range--)
	{
		if (get_value(stb->top) < pivot[low] && ++count[rb])
			st_rotate(cmd, stb);
		else if (true && ++count[pa])
		{
			st_push(cmd, sta, stb);
			if (get_value(sta->top) < pivot[high] && ++count[ra])
				st_rotate(cmd, sta);
		}
	}
	push_swap_a(cmd, sta, stb, count[pa] - count[ra]);
	rewind(cmd, sta, stb, count);
	push_swap_a(cmd, sta, stb, count[ra]);
	push_swap_b(cmd, sta, stb, count[rb]);
}
