/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:50:15 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/08 13:24:39 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*three;

	first = *stack;
	second = (*stack)->next;
	three = second->next;
	if ((first->value > second->value) && (three->value < first->value))
		ra(stack);
	else if ((second->value > first->value) && (second->value > three->value))
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

static void	rotate_min_to_top(t_node **stack_a, int len, int idx)
{
	int	i;

	i = len - idx;
	if (idx <= len / 2)
	{
		while (idx--)
			ra(stack_a);
	}
	else
	{
		while (i--)
			rra(stack_a);
	}
}

static void	locate_and_rotate_minimum(t_node **stack_a)
{
	t_node	*node;
	int		len;
	int		min_val;
	int		idx;

	node = *stack_a;
	min_val = node->value;
	idx = 0;
	len = 0;
	while (node)
	{
		if (node->value < min_val)
		{
			min_val = node->value;
			idx = len;
		}
		node = node->next;
		len++;
	}
	rotate_min_to_top(stack_a, len, idx);
}

static void	sort_small_more(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	push_count;

	len = stack_size(*stack_a);
	if (len < 4 || len > 5)
		return ;
	push_count = len - 3;
	while (push_count--)
	{
		locate_and_rotate_minimum(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_b, stack_a);
}

void	sort_small(t_node **stack_a, t_node **stack_b)
{
	int	len;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	len = stack_size(*stack_a);
	if (len == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4 || len == 5)
		sort_small_more(stack_a, stack_b);
}
