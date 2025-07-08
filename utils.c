/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:24 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/08 09:37:12 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	node_add_back(t_node **head, t_node *new)
{
	t_node	*cur;

	if (!head || !new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
}

int	stack_size(t_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	is_sorted(t_node *stack)
{
	t_node	*next_node;

	if (!stack)
		return (1);
	next_node = stack->next;
	while (stack->next)
	{
		if (stack->value > next_node->value)
			return (0);
		stack = stack->next;
		next_node = next_node->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
