/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:16:22 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/26 17:58:20 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix(t_list **stack_a, t_list **stack_b, int b_dig)
{
	int	i;
	int	temp_size;

	i = 0;
	while (i < b_dig)
	{
		temp_size = st_size(stack_a);
		while (temp_size--)
		{
			if (binary_check(((*stack_a)->val), i) == 0)
				push(stack_b, pop(stack_a), 2);
			else
			{
				rot(stack_a);
				write(1, "ra\n", 3);
			}
		}
		temp_size = st_size(stack_b);
		while (temp_size--)
			push(stack_a, pop(stack_b), 1);
		i++;
	}
}

char	*raw_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*temp;

	str = malloc(1);
	str[0] = '\0';
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**arr;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	if (input_checker(argc, argv))
		return (0);
	str = raw_str(argc, argv);
	arr = ft_split(str, ' ');
	i = count_arr(arr);
	while (i--)
	{
		if ((ft_atoi(arr[i]) == 0 && arr[i][0] != '0')
		|| (stack_a && dup_check(&stack_a, ft_atoi(arr[i])))
		|| (int)ft_atoi(arr[i]) != ft_atoi(arr[i]) || isnt_digit(arr[i]))
			return (free_list(stack_a, arr, str, 1));
		push(&stack_a, ft_atoi(arr[i]), 0);
	}
	if (is_sorted(&stack_a))
		return (free_list(stack_a, arr, str, 0));
	index_sort(&stack_a);
	sort_mode(count_arr(arr), &stack_a, &stack_b);
	return (free_list(stack_a, arr, str, 0));
}
