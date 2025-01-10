/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:38:13 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/21 15:49:34 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_position(t_stack *stack, int number)
{
	int				position;
	t_stack_node	*current;

	position = 0;
	current = stack->top_node;
	while (current != NULL)
	{
		if (current->value == number)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	ft_next_higher_num(t_stack *stack, int num)
{
	int				next_higher_number;
	t_stack_node	*tmp;

	next_higher_number = stack->max;
	tmp = stack->top_node;
	while (tmp != NULL)
	{
		if (tmp->value < next_higher_number && tmp->value > num)
			next_higher_number = tmp->value;
		tmp = tmp->next;
	}
	return (next_higher_number);
}
