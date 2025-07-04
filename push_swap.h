/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:54:15 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/04 16:18:16 by keitabe          ###   ########.fr       */
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
void				print_error(void);
void				parse_args(int ac, char *av[], t_node **stack_a);
void				sa_sb_swap(t_node **stack);
void				pa_pb_push(t_node **from, t_node **to);
void				ra_rb_rotate(t_node **stack);
void				rra_rrb_rev_rotate(t_node **stack);
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);

#endif
