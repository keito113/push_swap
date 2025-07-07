/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:30:18 by keitabe           #+#    #+#             */
/*   Updated: 2025/07/07 07:15:38 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
	parse_args(ac, av, &stack_a);
	stack_b = NULL;

}
