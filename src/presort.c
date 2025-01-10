/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:56:13 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/26 10:19:19 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
				ft_swap(&array[i], &array[j]);
			j++;
		}
		i++;
	}
}

static void	find_tertiles(t_stack *stack, int *f_tertile, int *s_tertile)
{
	int				*array;
	int				i;
	t_stack_node	*current;

	array = (int *)malloc(stack->size * sizeof(int));
	if (!array)
	{
		free_stack(stack);
		ft_printf("Error\nAllocation failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	current = stack->top_node;
	while (current)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	sort(array, stack->size);
	*f_tertile = array[stack->size / 3];
	*s_tertile = array[(stack->size / 3) * 2];
	free(array);
}

static void	find_third_max(t_stack *stack, int *max3)
{
	t_stack_node	*current;
	int				max1;
	int				max2;

	current = stack->top_node;
	max1 = current->value;
	max2 = current->value;
	*max3 = current->value;
	while (current)
	{
		if (current->value > max1)
		{
			*max3 = max2;
			max2 = max1;
			max1 = current->value;
		}
		else if (current->value > max2)
		{
			*max3 = max2;
			max2 = current->value;
		}
		else if (current->value > *max3)
			*max3 = current->value;
		current = current->next;
	}
}

static int	find_value_lowest_than_second_tertile(t_stack *stack, int s_tertile)
{
	t_stack_node	*current;

	current = stack->top_node;
	while (current)
	{
		if (current->value <= s_tertile)
			return (1);
		current = current->next;
	}
	return (0);
}

void	presort(t_push_swap *ps)
{
	int	current_value;
	int	max3;
	int	first_tertile;
	int	second_tertile;

	find_third_max(ps->stack_a, &max3);
	find_tertiles(ps->stack_a, &first_tertile, &second_tertile);
	while (find_value_lowest_than_second_tertile(ps->stack_a,
			second_tertile) && ps->stack_a->size > 3)
	{
		current_value = ps->stack_a->top_node->value;
		if (current_value <= second_tertile)
			push(ps->stack_a, ps->stack_b, "pb");
		else
			rotate(ps->stack_a, "ra");
	}
	while (ps->stack_a->size > 3)
	{
		current_value = ps->stack_a->top_node->value;
		if (current_value < max3)
			push(ps->stack_a, ps->stack_b, "pb");
		else
			rotate(ps->stack_a, "ra");
	}
}
