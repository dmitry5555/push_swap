/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:20:01 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/26 17:37:15 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	binary_check(int num, int pos)
{
	int	res;

	res = (num >> pos) & 1;
	return (res);
}

int	max_node(t_list **stack)
{
	int		max;
	t_list	*current;

	current = *stack;
	max = current->val;
	while (current->next)
	{
		if (max < current->next->val)
			max = current->next->val;
		current = current->next;
	}
	return (max);
}

int	is_sorted(t_list **stack)
{
	t_list	*current;

	if (!(*stack))
		return (0);
	current = (*stack);
	while (current)
	{
		if (current->next && (current->next->val < current->val))
			return (0);
		current = current->next;
	}
	return (1);
}

int	st_size(t_list **stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	swap_help(t_list **head, t_list *node, t_list **prev, t_list **curr)
{
	*prev = NULL;
	*curr = *head;
	while (*curr && *curr != node)
	{
		*prev = *curr;
		*curr = (*curr)->next;
	}
}
