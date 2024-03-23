/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:16:15 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/26 17:37:17 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	r_rot(t_list **stack)
{
	t_list	*last_node;
	t_list	*prev_node;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last_node = *stack;
		prev_node = NULL;
		while (last_node->next != NULL)
		{
			prev_node = last_node;
			last_node = last_node->next;
		}
		prev_node->next = NULL;
		last_node->next = *stack;
		*stack = last_node;
	}
}

void	rot(t_list **stack)
{
	t_list	*last_node;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last_node = *stack;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = *stack;
		*stack = (*stack)->next;
		last_node->next->next = NULL;
	}
}

void	push(t_list **stack, int val, int dir)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->val = val;
	new->next = *stack;
	*stack = new;
	if (dir == 1)
		write(1, "pa\n", 3);
	if (dir == 2)
		write(1, "pb\n", 3);
}

int	pop(t_list **stack)
{
	int		val;
	t_list	*temp;

	if (*stack == NULL)
	{
		write(1, "error\n", 5);
		exit(1);
	}
	val = (*stack)->val;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	return (val);
}

void	swap(t_list **head, t_list *node1, t_list *node2)
{
	t_list	*prev1;
	t_list	*prev2;
	t_list	*curr1;
	t_list	*curr2;
	t_list	*temp;

	swap_help(head, node1, &prev1, &curr1);
	swap_help(head, node2, &prev2, &curr2);
	if (prev1 == NULL)
		*head = curr2;
	else
		prev1->next = curr2;
	if (prev2 == NULL)
		*head = curr1;
	else
		prev2->next = curr1;
	temp = curr2->next;
	curr2->next = curr1->next;
	curr1->next = temp;
}
