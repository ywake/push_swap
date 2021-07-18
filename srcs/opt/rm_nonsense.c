#include "push_swap.h"

#include "stack.h"
#include "libft.h"

t_list	*search_drop(t_list **cmd, t_list *start, char *wd[2], char **ignore)
{
	t_list	*end;
	t_list	*tmp;

	if (!ft_strncmp(wd[0], start->content, ft_strlen(wd[0]) + 1))
	{
		end = start->next;
		while (end)
		{
			if (ignore && contain(ignore, end->content) + 1)
				end = end->next;
			else
				break ;
		}
		if (end && !ft_strncmp(wd[1], end->content, ft_strlen(wd[1]) + 1))
		{
			ft_lstdrop(cmd, end, free);
			tmp = start->next;
			ft_lstdrop(cmd, start, free);
			return (tmp);
		}
	}
	return (start);
}

void	rm_nonsense_(t_list **cmd, char *word[2], char **ignore)
{
	t_list	*cur;
	t_list	*save;

	cur = *cmd;
	while (cur)
	{
		save = cur;
		cur = search_drop(cmd, cur, word, ignore);
		if (cur != save)
			continue ;
		cur = search_drop(cmd, cur, (char *[2]){word[1], word[0]}, ignore);
		if (cur != save)
			continue ;
		cur = cur->next;
	}
}

size_t	rm_nonsense(t_list **cmd)
{
	size_t	before;
	size_t	after;

	before = ft_lstsize(*cmd);
	rm_nonsense_(cmd, (char *[2]){"pa", "pb"}, NULL);
	rm_nonsense_(cmd, (char *[2]){"ra", "rra"},
		(char *[4]){"sb", "rb", "rrb", NULL});
	rm_nonsense_(cmd, (char *[2]){"rb", "rrb"},
		(char *[4]){"sa", "ra", "rra", NULL});
	after = ft_lstsize(*cmd);
	return (after - before);
}
