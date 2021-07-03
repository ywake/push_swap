#include "push_swap.h"

#include <stdlib.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_list	*input;

	input = make_data(argc, argv);
	ft_lstclear(&input, free);
	return (0);
}
