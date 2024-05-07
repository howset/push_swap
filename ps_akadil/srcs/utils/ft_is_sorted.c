#include "ft_stack.h"

int	ft_is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->num[i] > a->num[i + 1])
			return (0);
		i++;
	}
	return (1);
}