/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:22:50 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/26 17:37:12 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_mode(int argc, t_list **stack_a, t_list **stack_b)
{
	if (argc == 2)
	{
		if ((*stack_a)->next->val < (*stack_a)->val)
			write(1, "ra\n", 3);
	}
	else if (argc == 3)
		three_sort(stack_a);
	else if (argc == 4)
		four_sort(stack_a, stack_b);
	else if (argc == 5)
		five_sort(stack_a, stack_b);
	else if (argc <= 100)
		radix(stack_a, stack_b, 7);
	else
		radix(stack_a, stack_b, 9);
}

void	any_sort(t_list **stack, int type)
{
	int		i;
	t_list	*current;
	t_list	*prev;

	current = *stack;
	prev = current;
	i = 0;
	while (current)
	{
		if (type == 1)
			current->i_bs = i;
		if (type == 3)
			current->val = i;
		if (current->val < prev->val && type == 2)
			swap(stack, prev, current);
		if (current->i_bs < prev->i_bs && type == 4)
			swap(stack, prev, current);
		i++;
		prev = current;
		current = current->next;
	}
}

void	index_sort(t_list **stack)
{
	int	i;

	i = st_size(stack);
	any_sort(stack, 1);
	while (i--)
		any_sort(stack, 2);
	any_sort(stack, 3);
	i = st_size(stack);
	while (i--)
		any_sort(stack, 4);
}

void	three_sort(t_list **stack)
{
	if ((*stack)->next->val < (*stack)->val
		&& (*stack)->next->next->val < (*stack)->val
		&& (*stack)->next->val < (*stack)->next->next->val && !is_sorted(stack))
	{
		rot(stack);
		write(1, "ra\n", 3);
	}
	if ((*stack)->next->val < (*stack)->val && !is_sorted(stack))
	{
		swap(stack, *stack, (*stack)->next);
		write(1, "sa\n", 3);
	}
	if ((*stack)->next->next->val < (*stack)->next->val && !is_sorted(stack))
	{
		r_rot(stack);
		write(1, "rra\n", 4);
	}
	if ((*stack)->next->val < (*stack)->val && !is_sorted(stack))
	{
		swap(stack, *stack, (*stack)->next);
		write(1, "sa\n", 3);
	}
}

void	five_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = st_size(stack_a);
	while (i--)
	{
		if ((*stack_a)->val == 0 || (*stack_a)->val == 1)
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
