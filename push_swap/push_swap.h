/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:15:01 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/03 13:59:21 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

enum e_definition
{
	AB = 1,
	BA = -1,
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
	int				min;
	int				max_depth;
}	t_stack;

t_stack			*create_stack(void);
t_stack_node	*create_new_node(int data);
int				push(t_stack *stack, int data);
int				pop(t_stack *stack);
void			display_stack(t_stack *list);
void			display_two_stack(t_stack *stack_a, t_stack *stack_b);
void			destroy_stack(t_stack **list);
int				stack_top(t_stack *stack);
int				stack_bottom(t_stack *stack);
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
int				is_stack_sorted(t_stack *stack);
void			destroy_stacks_and_exit(t_stack *stack_a, \
				t_stack *stack_b, int exit_status);
void			display_stack(t_stack *list);
void			error_exit(char *message, t_stack *stack_a, t_stack *stack_b);
void			push_swap(t_stack *stack_a, t_stack *stack_b);
size_t			stack_size(t_stack *stack);
void			sort_three_number(t_stack *stack_a);
void merge_sort(t_stack *stack_a, t_stack *stack_b, int flag, int depth);
int				get_median(t_stack *stack);
void			sort_three_number_b(t_stack *stack_b);
int				is_stack_sorted_b(t_stack *stack);




#endif