/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:18:40 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/08 10:21:09 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	ra_rb_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	ra_rb_rotate(b);
	write(1, "rb\n", 3);
}

void	rra(t_node **a)
{
	rra_rrb_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rra_rrb_rev_rotate(b);
	write(1, "rrb\n", 4);
}
