/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:27:20 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/21 13:28:33 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_stackadd_back(t_stack *stack, t_stack_node *new_node)
{
	t_stack_node	*last_el;

	if (!stack || !new_node)
		return ;
	if (stack->top_node == NULL)
	{
		stack->top_node = new_node;
		stack->size = 1;
		return ;
	}
	last_el = stack->top_node;
	while (last_el->next != NULL)
		last_el = last_el->next;
	last_el->next = new_node;
	stack->size++;
}

t_stack_node	*ft_stacknew(int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	ft_stacksize(t_stack *stack)
{
	size_t			count;
	t_stack_node	*current;

	if (!stack || !stack->top_node)
		return (0);
	count = 0;
	current = stack->top_node;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
