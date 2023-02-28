/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:15:01 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 13:28:25 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct t_stack_node {
	int					data;
	struct t_stack_node	*next;
	struct t_stack_node	*prev;
}	t_stack_node;

typedef struct list {
	t_stack_node	*top;
	t_stack_node	*headnode;
}	t_stack;

t_stack			*create_stack(void);
t_stack_node	*create_new_node(int data);
int				push(t_stack *list, int data);
int				pop(t_stack *list);
void			display_stack(t_stack *list);
void			destroy_stack(t_stack **list);
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

#endif