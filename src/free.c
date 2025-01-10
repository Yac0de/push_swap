/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:34:14 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/26 10:13:42 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = stack->top_node;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
