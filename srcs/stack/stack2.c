#include "stack.h"

#include "libft.h"
#include "data.h"

void	st_double(t_list **cmd, void (*st_any)(), t_stack *sta, t_stack *stb)
{
	st_any(NULL, sta);
	st_any(NULL, stb);
	if (cmd)
	{
		if (st_any == st_swap)
			add_cmd(cmd, "s", "s");
		if (st_any == st_rotate)
			add_cmd(cmd, "r", "r");
		if (st_any == st_rrotate)
			add_cmd(cmd, "rr", "r");
	}
}

bool	asc(int a, int b)
{
	if (a > b)
		return (true);
	return (false);
}

bool	desc(int a, int b)
{
	if (a < b)
		return (true);
	return (false);
}

bool	is_sorted(t_stack *stack, size_t range, bool (*cmp)(int, int))
{
	t_list	*cur;
	t_list	*next;

	cur = stack->top;
	if (cur != NULL)
		next = cur->next;
	if (range <= 1)
		next = NULL;
	while (range && cur && next)
	{
		if (cmp(get_value(cur), get_value(next)))
			return (false);
		cur = next;
		range--;
		if (range <= 1)
			next = NULL;
		else
			next = next->next;
	}
	return (true);
}
