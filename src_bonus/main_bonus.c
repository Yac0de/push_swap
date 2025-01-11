/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:43:03 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/27 15:53:12 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_stacks_b(t_push_swap *ps)
{
	ps->stack_a = malloc(sizeof(t_stack));
	if (ps->stack_a == NULL)
		return ;
	ps->stack_a->size = 0;
	ps->stack_a->min = INT_MAX;
	ps->stack_a->max = INT_MIN;
	ps->stack_a->top_node = NULL;
	ps->stack_b = malloc(sizeof(t_stack));
	if (ps->stack_b == NULL)
		return ;
	ps->stack_b->size = 0;
	ps->stack_b->min = INT_MAX;
	ps->stack_b->max = INT_MIN;
	ps->stack_a->count_moove = 0;
	ps->stack_b->count_moove = 0;
	ps->stack_b->top_node = NULL;
}

static int	ft_arraylen_b(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static void	fill_stack_a_b(t_push_swap *ps, int argc, char **argv,
			int is_allocated)
{
	int	i;
	int	*num;

	i = 1;
	if (argc == 2)
	{
		argc = ft_arraylen_b(argv);
		i = 0;
	}
	while (i < argc)
	{
		num = malloc(sizeof(int));
		if (!num)
		{
			ft_printf("Error\nAllocation failed\n");
			free_stack_and_argv_b(ps->stack_a, ps->stack_b, argv, is_allocated);
			exit(EXIT_FAILURE);
		}
		*num = ft_atoi(argv[i]);
		ft_stackadd_back_b(ps->stack_a, ft_stacknew_b(*num));
		free(num);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;
	int			is_allocated;

	is_allocated = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		is_allocated = 1;
		if (!argv || !argv[0])
			return (free_stack_and_argv_b(NULL, NULL, argv, is_allocated),
				ft_printf("Error\n"), 1);
	}
	check_input_b(argc, argv, is_allocated);
	init_stacks_b(&push_swap);
	fill_stack_a_b(&push_swap, argc, argv, is_allocated);
	if (is_allocated)
		free_argv_b(argv);
	get_instruction_b(&push_swap);
	end_message_b(push_swap.stack_a, push_swap.stack_b);
	return (free_stack_and_argv_b(push_swap.stack_a, push_swap.stack_b,
			NULL, 0), 0);
}
