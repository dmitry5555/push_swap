/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:59:00 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/28 17:33:21 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	dup_check(t_list **stack, int num)
{
	t_list	*current;

	current = (*stack);
	while (current)
	{
		if (current->val == num)
			return (1);
		current = current->next;
	}
	return (0);
}


void	sort_b(t_list **stack)
{
	if ((*stack)->val == 0)
	{
		rot(stack);
		write(1, "rb\n", 3);
	}
}

void	four_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = st_size(stack_a);
	while (i--)
	{
		if ((*stack_a)->val == 0)
			push(stack_b, pop(stack_a), 2);
		else
		{
			rot(stack_a);
			write(1, "ra\n", 3);
		}
	}
	three_sort(stack_a);
	sort_b(stack_b);
	i = st_size(stack_b);
	while (i--)
		push(stack_a, pop(stack_b), 1);
}

int	free_list(t_list *head, char **arr, char *str, int err)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(str);
	free_arr(arr);
	if (err == 1)
		write(2, "Error\n", 6);
	return (0);
}

size_t	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
