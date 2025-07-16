/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:15:16 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/15 12:22:34 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *stack)
{
	int	bit_count;
	int	size;

	if (stack == NULL)
		return (0);
	size = stack_size(stack);
	bit_count = 0;
	while ((1 << bit_count) < size)
		bit_count++;
	return (bit_count);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	max_bits;
	int	bit;

	max_bits = get_max_bits(*stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		size = stack_size(*stack_a);
		while (size)
		{
			if (((*stack_a)->rank >> bit) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			size--;
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		bit++;
	}
}

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	parse_args(ac, av, &stack_a);
	stack_b = NULL;
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	else if (stack_size(stack_a) <= 5)
		sort_small(&stack_a, &stack_b);
	else
	{
		coordinate_compression(&stack_a);
		radix_sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
