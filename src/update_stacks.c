/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:43:17 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/21 15:49:50 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	find_max(t_stack *stack)
{
	t_stack_node	*current;
	int				max;

	current = stack->top_node;
	max = INT_MIN;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

static int	find_min(t_stack *stack)
{
	t_stack_node	*current;
	int				min;

	current = stack->top_node;
	min = INT_MAX;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void	update_stacks(t_push_swap *ps)
{
	ps->stack_a->size = ft_stacksize(ps->stack_a);
	ps->stack_b->size = ft_stacksize(ps->stack_b);
	if (ps->stack_a->size > 0)
	{
		ps->stack_a->max = find_max(ps->stack_a);
		ps->stack_a->min = find_min(ps->stack_a);
	}
	if (ps->stack_b->size > 0)
	{
		ps->stack_b->max = find_max(ps->stack_b);
		ps->stack_b->min = find_min(ps->stack_b);
	}
}
