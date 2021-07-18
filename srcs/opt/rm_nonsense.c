#include "push_swap.h"

#include "stack.h"
#include "libft.h"

void	rm_nonsense_push(t_list **cmd, char *st1, char *nd2)
{
	t_list	*cur;
	t_list	*tmp;

	cur = *cmd;
	while (cur)
	{
		if ((!ft_strncmp(st1, cur->content, ft_strlen(st1) + 1) && cur->next \
			&& !ft_strncmp(nd2, cur->next->content, ft_strlen(nd2) + 1)) \
			|| \
			(!ft_strncmp(nd2, cur->content, ft_strlen(nd2) + 1) && cur->next \
			&& !ft_strncmp(st1, cur->next->content, ft_strlen(st1) + 1)))
		{
			ft_lstdrop(cmd, cur->next, free);
			tmp = cur->next;
			ft_lstdrop(cmd, cur, free);
			cur = tmp;
			continue ;
		}
		cur = cur->next;
	}
}

void	rm_nonsense(t_list **cmd)
{
	rm_nonsense_push(cmd, "pa", "pb");
	rm_nonsense_push(cmd, "ra", "rra");
	rm_nonsense_push(cmd, "rb", "rrb");
}
