/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:21:18 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/08 12:20:47 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && '9' >= str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_node *head, int value)
{
	while (head)
	{
		if (head->value == value)
			return (1);
		head = head->next;
	}
	return (0);
}

void	print_error(t_node **stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	exit(1);
}

void	parse_args(int ac, char *av[], t_node **stack_a)
{
	int		i;
	long	val;

	if (ac < 2)
		return ;
	i = 1;
	while (av[i])
	{
		val = ft_atol(av[i]);
		if (val * -1 < INT_MIN || val > INT_MAX)
			print_error(stack_a);
		if (!is_numeric(av[i]))
			print_error(stack_a);
		else if (is_duplicate(*stack_a, (int)(val)))
			print_error(stack_a);
		else
			node_add_back(stack_a, node_new((int)(val)));
		i++;
	}
}
