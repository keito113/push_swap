/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:26:51 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/07 15:36:49 by keitabe          ###   ########.fr       */
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

void	sort_small(t_node **stack_a, t_node **stack_b)
{
	int		len;
	t_node	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	len = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len = 1)
		return ;
	else if (len == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa_sb_swap(stack_a);
	}
	else if (len == 3)
		sort_three(stack_a);
	else if (len = 4 || len == 5)
		sort_small_more(stack_a, stack_b);
}

void	sort_small_more(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	push_count;
	int	i;
	int	min_ind;
	int	min_val;

	if (len < 4 || len > 5)
		return ;
	push_count = len - 3;
	while (push_count)
	{
		len = stack_size(stack_a);
		i = 1;
		min_val = (*stack_a)->value;
		min_ind = 0;
		while (i <= len)
		{
			ra_rb_rotate(stack_a);
			if ((*stack_a)->value < min_val)
			{
				min_val = (*stack_a)->value;
				min_ind = i;
			}
			i++;
		}
		i = len - min_ind;
		if (min_ind <= len / 2)
		{
			while (min_ind)
			{
				ra_rb_rotate(stack_a);
				min_ind--;
			}
		}
		else
		{
			while (i != 0)
			{
				rra_rrb_rev_rotate(stack_a);
				i--;
			}
		}
		pa_pb_push(stack_a, stack_b);
		push_count--;
	}
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
