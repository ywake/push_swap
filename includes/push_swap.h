#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

enum e_stacks
{
	st_a,
	st_b,
	st_len,
};

typedef struct s_state
{
	t_stack	*sta;
	t_stack	*stb;
	t_list	*a_next;
	t_list	**movable;
	t_list	**cmd;
	t_list	*find;
	size_t	search_max;
	int		range;
}	t_state;

void	optimize(t_list **cmd);
size_t	rm_nonsense(t_list **cmd);
void	push_swap_a(t_list **cmd, t_stack *sta, t_stack *stb, int range);
void	push_swap_b(t_list **cmd, t_stack *sta, t_stack *stb, int range);
void	small_swap(t_list **cmd, t_stack *st[st_len],
			int range, enum e_stacks ope);
// void	dfs(t_state *state, char *cmd, size_t move_num);
void	dfs(t_state *state, char **cmds, char *cmd, size_t move_num);
bool	is_movable(t_state *state, t_list *elem);

#endif
