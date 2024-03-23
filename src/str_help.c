/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:46:57 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/26 17:59:56 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

int	input_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = 0;
		flag = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				flag = 0;
			if (!argv[i][j] || argv[i][0] == '\0')
				flag = 2;
			j++;
		}
		if (0 < flag)
			return (write(2, "Error\n", 6));
		i++;
	}
	return (0);
}
