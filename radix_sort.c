/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:26:51 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/06 17:00:01 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *stack)
{
	int	max_val;
	int	bit_count;

	if (stack == NULL)
		return (0);
	max_val = stack->value;
	while (stack)
	{
		if (max_val < stack->value)
			max_val = stack->value;
		stack = stack->next;
	}
	bit_count = 0;
	while ((max_val >> bit_count) != 0)
	{
		bit_count++;
	}
	return (bit_count);
}

static void	sort_three(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*three;

	first = *stack;
	second = (*stack)->next;
	three = second->next;
	if ((first->value > second->value) && (three->value < first->value))
		ra_rb_rotate(stack);
	else if ((second->value > first->value) && (second->value > three->value))
		rra_rrb_rev_rotate(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa_sb_swap(stack);
	else
		return ;
}

void	sort_small(t_node **stack)
{
	int		i;
	t_node	*tmp;
	t_node	*first;
	t_node	*second;
	t_node	*three;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	first = *stack;
	second = (*stack)->next;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 2)
	{
		if (first->value > second->value)
			sa_sb_swap(stack);
	}
	else if (i == 3)
		sort_three(stack);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	element_count;
	int	max_bits;
	int	bit;

	max_bits = get_max_bits(*stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		element_count = stack_size(*stack_a);
		while (element_count)
		{
			if (((*stack_a)->value >> bit) & 1)
				ra_rb_rotate(stack_a);
			else
				pa_pb_push(stack_a, stack_b);
			element_count--;
		}
		while (*stack_b)
			pa_pb_push(stack_b, stack_a);
		bit++;
	}
}
