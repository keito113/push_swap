/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:54:15 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/02 13:34:13 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
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

#endif
