/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_error_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:23:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/31 12:54:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_error(void);
void		ft_free_2arraystr(char **trash);
int			ft_free_2arraystr_error_0(char **trash);
int			ft_free_2arraystr_0(char **trash);
int			ft_free_arrayint_0(int *trash);

int	ft_free_2arraystr_error_0(char **trash)
{
	ft_error();
	return (ft_free_2arraystr_0(trash));
}

int	ft_free_2arraystr_0(char **trash)
{
	ft_free_2arraystr(trash);
	return (0);
}

void	ft_free_2arraystr(char **trash)
{
	int	i;

	i = 0;
	while (trash && trash[i])
		free(trash[i++]);
	free(trash);
}

int	ft_free_arrayint_0(int *trash)
{
	free(trash);
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}
