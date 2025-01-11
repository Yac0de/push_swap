/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:55:42 by ymeziane          #+#    #+#             */
/*   Updated: 2024/01/02 11:53:36 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

typedef struct s_context
{
	char				**argv;
	int					is_allocated;
}						t_context;

typedef struct s_rotation_info
{
	int					count_rotate_a;
	int					count_reverse_rotate_a;
	int					count_rotate_b;
	int					count_reverse_rotate_b;
}						t_rotation_info;

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node		*top_node;
	int					min;
	int					max;
	int					size;
	int					count_moove;
}						t_stack;

typedef struct s_push_swap
{
	t_stack				*stack_a;
	t_stack				*stack_b;
}						t_push_swap;

// MAIN
void					check_input(int argc, char **argv, int is_allocated);
void					turk_sort(t_push_swap *ps, t_context *ctx);

// TURK_SORT
void					update_stacks(t_push_swap *ps);
void					presort(t_push_swap *ps, t_context *ctx);
int						find_min_cost_number(t_push_swap *ps);
void					move(t_push_swap *ps, int num_to_push);

// COUNT_ROTATE
void					count_rotate_top_b(t_stack *stack_b, int num_to_push,
							t_rotation_info *rotate_info);
void					count_rotate_correct_top_b(t_push_swap *ps,
							int num_to_push, t_rotation_info *rotate_info);

// UTILS
int						find_position(t_stack *stack, int number);
int						ft_next_higher_num(t_stack *stack, int num);

// OPERATIONS
void					swap(t_stack *stack, char *operation);
void					swap_both(t_stack *stack_a, t_stack *stack_b);
void					push(t_stack *src_stack, t_stack *dst_stack,
							char *operation);
void					rotate(t_stack *stack, char *operation);
void					rotate_both(t_stack *stack_a, t_stack *stack_b);
void					reverse_rotate(t_stack *stack, char *operation);
void					reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

// FT_STACK
void					ft_stackadd_back(t_stack *stack,
							t_stack_node *new_node);
t_stack_node			*ft_stacknew(int value);
int						ft_stacksize(t_stack *stack);

// FREE
void					free_stack_and_argv(t_stack *stack_a, t_stack *stack_b,
							char **argv, int is_allocated);
void					free_argv(char **argv);

//////////////////////////////////////////////////////////////////

// BONUS

// MAIN BONUS
void					check_input_b(int argc, char **argv, int is_allocated);

// OPERATIONS BONUS
void					swap_b(t_stack *stack);
void					swap_both_b(t_stack *stack_a, t_stack *stack_b);
void					push_b(t_stack *src_stack, t_stack *dst_stack);
void					rotate_b(t_stack *stack);
void					rotate_both_b(t_stack *stack_a, t_stack *stack_b);
void					reverse_rotate_b(t_stack *stack);
void					reverse_rotate_both_b(t_stack *stack_a,
							t_stack *stack_b);

// HANDLE INPUT INSTRUCTION BONUS
void					get_instruction_b(t_push_swap *push_swap);

// ERROR BONUS
int						print_error_with_arg_b(const char *message,
							const char *arg);

// FT_STACK BONUS
void					ft_stackadd_back_b(t_stack *stack,
							t_stack_node *new_node);
t_stack_node			*ft_stacknew_b(int value);
int						ft_stacksize_b(t_stack *stack);

// FREE BONUS
void					free_stack_b(t_stack *stack);
void					free_stack_and_argv_b(t_stack *stack_a,
							t_stack *stack_b, char **argv, int is_allocated);
void					free_argv_b(char **argv);

// END MESSAGE
void					end_message_b(t_stack *a, t_stack *b);

#endif
