#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include "libft.h"
# include "stack.h"

void	simulate_stack(t_list *cmd, t_stack *sta, t_stack *stb);
bool	checker(t_list *cmd, t_stack *sta, t_stack *stb);

#endif
