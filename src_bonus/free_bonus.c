/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:34:14 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/27 15:45:22 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack_b(t_stack *stack)
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

void	free_argv_b(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
