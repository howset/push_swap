/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:31:39 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/26 16:41:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
    Goal:   Check if the argv is valid or not

    How:    Go through each character and check if it digit or
            not. If it is c=='-', then check for the next character
            if it is digit, then ok
*/
int	ft_check_normal(char **argv, int isString)
{
	int	i;
	int	j;

	i = 1 - isString;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				if (argv[i][j] != '-' || (argv[i][j + 1] < '0' || argv[i][j
						+ 1] > '9'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
