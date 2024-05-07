#include "ft_bonus.h"

int	ft_is_empty(t_stack *b)
{
	if (b->size == 0)
		return (1);
	return (0);
}

int	ft_result_free_return(t_stack *a, t_stack *b, int res)
{
	if (res == 1)
		write (1, "Ok\n", 3);
	else
		write (1, "Ko\n", 3);
	return (ft_free_stacks_0(a, b));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}
