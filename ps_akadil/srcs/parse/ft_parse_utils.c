/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:30:48 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/26 13:02:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_check_for_duplicates(int num, int *con, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		if (con[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_n_word(char const *s, char c)
{
	int	i;
	int	n;
	int	checker;

	n = 0;
	i = 0;
	checker = 1;
	while (s[i])
	{
		if (s[i] != c && checker == 1)
		{
			checker = 0;
			n++;
		}
		else if (s[i] == c && checker == 0)
		{
			checker = 1;
		}
		i++;
	}
	return (n);
}
