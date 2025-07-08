/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:54:15 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/08 12:01:30 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

t_node				*node_new(int value);
void				node_add_back(t_node **head, t_node *new);
int					is_numeric(const char *str);
int					is_duplicate(t_node *head, int value);
void				print_error(t_node **stack);
void				parse_args(int ac, char *av[], t_node **stack_a);
void				sa_sb_swap(t_node **stack);
void				pa_pb_push(t_node **from, t_node **to);
void				ra_rb_rotate(t_node **stack);
void				rra_rrb_rev_rotate(t_node **stack);
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);
void				free_stack(t_node **stack);
void				sort_small(t_node **stack, t_node **stack_b);
void				radix_sort(t_node **stack_a, t_node **stack_b);
void				sa(t_node **a);
void				sb(t_node **b);
void				pa(t_node **b, t_node **a);
void				pb(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);

#endif
