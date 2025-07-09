/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:15:16 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/09 15:42:06 by keitabe          ###   ########.fr       */
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
			if (((*stack_a)->value >> bit) & 1)
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
	int		count;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	parse_args(ac, av, &stack_a);
	count = stack_size(stack_a);
	stack_b = NULL;
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	else if (count <= 5)
		sort_small(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

// #include "push_swap.h"
// #include <stdio.h>

// static void	print_stack(t_node *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d", stack->value);
// 		if (stack->next)
// 			printf(" ");
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

// int	main(int ac, char *av[])
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	int		count;

// 	if (ac < 2)
// 		return (0);
// 	stack_a = NULL;
// 	parse_args(ac, av, &stack_a);
// 	count = stack_size(stack_a);
// 	stack_b = NULL;
// 	if (!is_sorted(stack_a))
// 	{
// 		if (count <= 5)
// 			sort_small(&stack_a, &stack_b);
// 		else
// 			radix_sort(&stack_a, &stack_b);
// 	}
// 	print_stack(stack_a);
// 	free_stack(&stack_a);
// 	return (0);
// }
