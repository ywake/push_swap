#include "stack.h"

#include "error.h"

bool	do_cmd(t_list **cmds, t_stack **st, char **valid_list, char *cmd)
{
	if (cmd == NULL || !(contain(valid_list, cmd) + 1))
		return (false);
	if (cmds != NULL)
		add_cmd(cmds, cmd, "");
	if (contain((char *[]){"sa", "ss", NULL}, cmd) + 1)
		st_swap(NULL, st[AA]);
	if (contain((char *[]){"sb", "ss", NULL}, cmd) + 1)
		st_swap(NULL, st[BB]);
	if (!ft_strcmp("pa", cmd))
		st_push(NULL, st[AA], st[BB]);
	if (!ft_strcmp("pb", cmd))
		st_push(NULL, st[BB], st[AA]);
	if (contain((char *[]){"ra", "rr", NULL}, cmd) + 1)
		st_rotate(NULL, st[AA]);
	if (contain((char *[]){"rb", "rr", NULL}, cmd) + 1)
		st_rotate(NULL, st[BB]);
	if (contain((char *[]){"rra", "rrr", NULL}, cmd) + 1)
		st_rrotate(NULL, st[AA]);
	if (contain((char *[]){"rrb", "rrr", NULL}, cmd) + 1)
		st_rrotate(NULL, st[BB]);
	return (true);
}

bool	undo_cmd(t_list **cmds, t_stack **st, char **vald_list, char *cmd)
{
	if (cmd == NULL || !(contain(vald_list, cmd) + 1))
		return (false);
	if (cmds)
		ft_lstdrop(cmds, *cmds, free);
	if (contain((char *[]){"sa", "ss", NULL}, cmd) + 1)
		st_swap(NULL, st[AA]);
	if (contain((char *[]){"sb", "ss", NULL}, cmd) + 1)
		st_swap(NULL, st[BB]);
	if (!ft_strcmp("pa", cmd))
		st_push(NULL, st[BB], st[AA]);
	if (!ft_strcmp("pb", cmd))
		st_push(NULL, st[AA], st[BB]);
	if (contain((char *[]){"ra", "rr", NULL}, cmd) + 1)
		st_rrotate(NULL, st[AA]);
	if (contain((char *[]){"rb", "rr", NULL}, cmd) + 1)
		st_rrotate(NULL, st[BB]);
	if (contain((char *[]){"rra", "rrr", NULL}, cmd) + 1)
		st_rotate(NULL, st[AA]);
	if (contain((char *[]){"rrb", "rrr", NULL}, cmd) + 1)
		st_rotate(NULL, st[BB]);
	return (true);
}

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
