/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:55:57 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/10 15:19:09 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*list_to_array(t_node *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		print_error(&stack);
		return (NULL);
	}
	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	map_ranks(t_node *stack, int *sorted_arr, int size)
{
	int	idx;

	while (stack)
	{
		idx = 0;
		while (idx < size)
		{
			if (sorted_arr[idx] == stack->value)
			{
				stack->rank = idx;
				break ;
			}
			idx++;
		}
		stack = stack->next;
	}
}

void	coordinate_compression(t_node **stack)
{
	int	size;
	int	*sorted_arr;

	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	sorted_arr = list_to_array(*stack, size);
	if (!sorted_arr)
		return ;
	sort_array(sorted_arr, size);
	map_ranks(*stack, sorted_arr, size);
	free(sorted_arr);
}
