#include "checker.h"

#include "debug.h"
#include "error.h"

void	simulate_stack(t_list *cmd, t_stack *sta, t_stack *stb)
{
	while (cmd)
	{
		if (contain((char *[]){"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
				"rra", "rrb", "rrr", NULL}, cmd->content) == -1)
			error();
		if (contain((char *[3]){"sa", "ss", NULL}, cmd->content) + 1)
			st_swap(NULL, sta);
		if (contain((char *[3]){"sb", "ss", NULL}, cmd->content) + 1)
			st_swap(NULL, stb);
		if (!ft_strcmp("pa", cmd->content))
			st_push(NULL, sta, stb);
		if (!ft_strcmp("pb", cmd->content))
			st_push(NULL, stb, sta);
		if (contain((char *[3]){"ra", "rr", NULL}, cmd->content) + 1)
			st_rotate(NULL, sta);
		if (contain((char *[3]){"rb", "rr", NULL}, cmd->content) + 1)
			st_rotate(NULL, stb);
		if (contain((char *[3]){"rra", "rrr", NULL}, cmd->content) + 1)
			st_rrotate(NULL, sta);
		if (contain((char *[3]){"rrb", "rrr", NULL}, cmd->content) + 1)
			st_rrotate(NULL, stb);
		cmd = cmd->next;
	}
}

bool	checker(t_list *cmd, t_stack *sta, t_stack *stb)
{
	simulate_stack(cmd, sta, stb);
	if (stb->len != 0)
		return (false);
	if (is_sorted(sta))
		return (true);
	return (false);
}
