/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_simple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:19:00 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/21 13:33:17 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack, char *operation)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack && stack->top_node && stack->top_node->next)
	{
		first = stack->top_node;
		second = first->next;
		first->next = second->next;
		second->next = first;
		stack->top_node = second;
		if (ft_strcmp(operation, "") != 0)
		{
			write(1, operation, ft_strlen(operation));
			write(1, "\n", 1);
		}
	}
	stack->count_moove++;
}

void	push(t_stack *src_stack, t_stack *dst_stack, char *operation)
{
	t_stack_node	*first;

	if (src_stack && src_stack->top_node)
	{
		first = src_stack->top_node;
		src_stack->top_node = src_stack->top_node->next;
		first->next = dst_stack->top_node;
		dst_stack->top_node = first;
		src_stack->size--;
		dst_stack->size++;
		write(1, operation, ft_strlen(operation));
		write(1, "\n", 1);
	}
	src_stack->count_moove++;
}

void	rotate(t_stack *stack, char *operation)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (stack && stack->top_node && stack->top_node->next)
	{
		first = stack->top_node;
		last = stack->top_node;
		while (last->next)
		{
			last = last->next;
		}
		stack->top_node = first->next;
		first->next = NULL;
		last->next = first;
		if (ft_strcmp(operation, "") != 0)
		{
			write(1, operation, ft_strlen(operation));
			write(1, "\n", 1);
		}
	}
	stack->count_moove++;
}

void	reverse_rotate(t_stack *stack, char *operation)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if (stack && stack->top_node && stack->top_node->next)
	{
		last = stack->top_node;
		before_last = NULL;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		if (before_last)
		{
			before_last->next = NULL;
			last->next = stack->top_node;
			stack->top_node = last;
		}
		if (ft_strcmp(operation, "") != 0)
		{
			write(1, operation, ft_strlen(operation));
			write(1, "\n", 1);
		}
	}
	stack->count_moove++;
}
