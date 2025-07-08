/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:13:03 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/08 10:24:50 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	sa_sb_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	sa_sb_swap(b);
	write(1, "sb\n", 3);
}

void	pa(t_node **b, t_node **a)
{
	pa_pb_push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	pa_pb_push(a, b);
	write(1, "pb\n", 3);
}
