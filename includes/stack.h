#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	char		*name;
	int			len;
	t_list		*top;
	t_list		*btm;
}	t_stack;

void	st_swap(t_list **cmd, t_stack *stack);
void	st_push(t_list **cmd, t_stack *dst, t_stack *src);
void	st_rotate(t_list **cmd, t_stack *stack);
void	st_rrotate(t_list **cmd, t_stack *stack);
void	add_cmd(t_list **cmd, char *str, char *stack_name);
void	st_double(t_list **cmd, void (*st_any)(), t_stack *sta, t_stack *stb);
bool	is_sorted(t_stack *stack, size_t range, bool (*cmp)(int, int));
bool	asc(int a, int b);
bool	desc(int a, int b);

#endif
