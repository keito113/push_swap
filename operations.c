/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:40:51 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/09 15:49:57 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb_swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	pa_pb_push(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!from || !to || *from == NULL)
		return ;
	tmp = *from;
	*from = tmp->next;
	tmp->next = *to;
	*to = tmp;
}

void	ra_rb_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rra_rrb_rev_rotate(t_node **stack)
{
	t_node	*sec_last;
	t_node	*last;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	sec_last = *stack;
	while (sec_last->next->next != NULL)
		sec_last = sec_last->next;
	last = sec_last->next;
	sec_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
