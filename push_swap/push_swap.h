/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:15:01 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/09 11:33:00 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

enum e_definition
{
	ERROR = -1,
	COMPLETE = 0,
	CONTINUE = 2,
};

typedef struct t_stack_node {
	int					data;
	struct t_stack_node	*next;
	struct t_stack_node	*prev;
}	t_stack_node;

typedef struct list {
	t_stack_node	*top;
	t_stack_node	*head;
	size_t			size;
	int				small_pivot;
	int				large_pivot;
}	t_stack;

t_stack			*create_stack(void);
t_stack_node	*create_new_node(int data);
int				valid_args(char *av, t_stack *stack_a);
int				push(t_stack *stack, int data);
int				pop(t_stack *stack);
void			display_two_stack(t_stack *stack_a, t_stack *stack_b);
void			destroy_stack(t_stack **list);
int				stack_top(t_stack *stack);
int				is_stack_empty(t_stack *stack);
void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);
void			sa(t_stack *stack_a);
void			sb(t_stack *stack_b);
void			ss(t_stack *stack_a, t_stack *stack_b);
void			rra(t_stack *stack_a);
void			rrb(t_stack *stack_b);
void			rrr(t_stack *stack_a, t_stack *stack_b);
void			ra(t_stack *stack_a);
void			rb(t_stack *stack_b);
void			rr(t_stack *stack_a, t_stack *stack_b);
int				fill_stack(t_stack *stack_a, int argc, char **argv);
void			destroy_stacks_and_exit(t_stack *stack_a, \
				t_stack *stack_b, int exit_status);
void			error_exit(t_stack *stack_a, t_stack *stack_b);
void			push_swap(t_stack *stack_a, t_stack *stack_b);
size_t			stack_size(t_stack *stack);
int				is_stack_sorted_a(t_stack *stack);
int				is_stack_sorted_b(t_stack *stack);
int				pattern_three_numbers(t_stack *stack);
int				stack_min(t_stack *stack, int limit);
int				stack_max(t_stack *stack, int range);

//sort_numbers.c
int				sort_b(t_stack *stack_b);
int				sort_a(t_stack *stack_a);

#endif