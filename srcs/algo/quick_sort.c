#include "push_swap.h"

#include "data.h"
#include "stack.h"
#include "debug.h"
#include "validation.h"

enum	e_pivot
{
	LOW,
	HIGH,
	PIV_LEN,
};

enum	e_count
{
	RA,
	PA,
	RB,
	PB,
	CNT_LEN,
};

void	init(t_stack *stack, int range, int piv[PIV_LEN], int count[CNT_LEN])
{
	t_list	*sorted;
	int		i;

	sorted = ft_lstndup(stack->top, range);
	ft_lst_sort(&sorted, cmp);
	piv[LOW] = ((t_data *)ft_lst_at(sorted, range / 3)->content)->val;
	piv[HIGH] = ((t_data *)ft_lst_at(sorted, range * 2 / 3)->content)->val;
	ft_lstclear(&sorted, free);
	i = 0;
	while (i < CNT_LEN)
	{
		count[i] = 0;
		i++;
	}
}

void	rewind(t_list **cmd, t_stack *sta, t_stack *stb, int count[CNT_LEN])
{
	int	i;

	i = 0;
	while (i < (int)ft_min(count[RA], count[RB]))
	{
		st_double(cmd, st_rrotate, sta, stb);
		i++;
	}
	while (i < count[RA])
	{
		st_rrotate(cmd, sta);
		i++;
	}
	while (i < count[RB])
	{
		st_rrotate(cmd, stb);
		i++;
	}
}

void	push_swap_a(t_list **cmd, t_stack *sta, t_stack *stb, int range)
{
	int	pivot[PIV_LEN];
	int	count[CNT_LEN];

	if (range <= 5)
		return (small_swap(cmd, (t_stack *[ST_LEN]){sta, stb}, range, AA));
	init(sta, range, pivot, count);
	while (range--)
	{
		if (get_value(sta->top) >= pivot[HIGH] && ++count[RA])
			st_rotate(cmd, sta);
		else
		{
			st_push(cmd, stb, sta);
			count[PB]++;
			if (get_value(stb->top) >= pivot[LOW] && ++count[RB])
				st_rotate(cmd, stb);
		}
	}
	rewind(cmd, sta, stb, count);
	push_swap_a(cmd, sta, stb, count[RA]);
	push_swap_b(cmd, sta, stb, count[RB]);
	push_swap_b(cmd, sta, stb, count[PB] - count[RB]);
}

void	push_swap_b(t_list **cmd, t_stack *sta, t_stack *stb, int range)
{
	int	pivot[PIV_LEN];
	int	count[CNT_LEN];

	if (range <= 5)
		return (small_swap(cmd, (t_stack *[ST_LEN]){sta, stb}, range, BB));
	init(stb, range, pivot, count);
	while (range--)
	{
		if (get_value(stb->top) < pivot[LOW] && ++count[RB])
			st_rotate(cmd, stb);
		else if (true && ++count[PA])
		{
			st_push(cmd, sta, stb);
			if (get_value(sta->top) < pivot[HIGH] && ++count[RA])
				st_rotate(cmd, sta);
		}
	}
	push_swap_a(cmd, sta, stb, count[PA] - count[RA]);
	rewind(cmd, sta, stb, count);
	push_swap_a(cmd, sta, stb, count[RA]);
	push_swap_b(cmd, sta, stb, count[RB]);
}
