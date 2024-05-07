/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:06:12 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/03 17:31:42 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnbr(char *nbr);
int	ft_isduplicate(int nbr, char *argv[], int i);

// check if arguments are valid
void	ft_argcheck(int argc, char *argv[])
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnbr(args[i]))
			ft_prt_err("Error\n", 2);
		if (ft_isduplicate(tmp, args, i))
			ft_prt_err("Error\n", 2);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_prt_err("Error\n", 2);
		i++;
	}
	if (argc == 2)
		free_args(args);
}

// check if string is number
int	ft_isnbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

// check if there is duplicate
int	ft_isduplicate(int nbr, char *argv[], int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nbr)
			return (1);
		i++;
	}
	return (0);
}
