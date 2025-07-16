/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:55:57 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/15 14:57:35 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*list_to_array(t_node *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		print_error(&stack);
	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	return (arr);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_qsort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = arr[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
			ft_swap(&arr[i++], &arr[j--]);
	}
	if (left < j)
		ft_qsort(arr, left, j);
	if (i < right)
		ft_qsort(arr, i, right);
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
	ft_qsort(sorted_arr, 0, size - 1);
	map_ranks(*stack, sorted_arr, size);
	free(sorted_arr);
}
