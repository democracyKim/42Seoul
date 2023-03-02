/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:12:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/02 14:43:08 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_top(t_stack *stack)
{
    if (stack == NULL || stack->top == NULL)
        return (-1);
    return (stack->top->data);
}

int stack_bottom(t_stack *stack)
{
    if (stack == NULL || stack->top == NULL)
        return (-1);
    return (stack->head->data);
}

int is_stack_empty(t_stack *stack)
{
    return (stack == NULL || stack->top == NULL);
}

