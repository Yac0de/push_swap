/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_message_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:34:24 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/27 15:49:08 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_sorted_b(t_stack *stack)
{
	t_stack_node	*current;

	current = stack->top_node;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	end_message_b(t_stack *a, t_stack *b)
{
	if (is_sorted_b(a) && b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
