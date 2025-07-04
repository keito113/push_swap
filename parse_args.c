/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:21:18 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/04 10:37:41 by keitabe          ###   ########.fr       */
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

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_args(int ac, char *av[], t_node **stack_a)
{
	int	i;
	int	val;

	if (ac < 2)
		return ;
	i = 1;
	while (av[i])
	{
		val = ft_atoi(av[i]);
		if (!is_numeric(av[i]))
			print_error();
		else if (is_duplicate(*stack_a, val))
			print_error();
		else
			node_add_back(stack_a, node_new(val));
		i++;
	}
}
