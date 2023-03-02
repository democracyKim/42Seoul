/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/02 12:59:33 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void stack_to_array(t_stack *stack, int *arr, int size)
{
	t_stack_node *node;
	int i;

	node = stack->top;
	i = 0;
	while (i < size)
	{
		arr[i] = node->data;
		node = node->prev;
		i++;
	}
}

static int partition(int *arr, int low, int high)
{
    int pivot;
    int i;
    int j;
	int temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
    while (j <= high - 1)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

static void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int get_median(t_stack *stack)
{
	int *arr;
	int median;
    int size = stack_size(stack);

	size = stack_size(stack);
    if (is_stack_empty(stack) || size == 1)
        return stack_top(stack);
	arr = (int *)malloc(size * sizeof(int));
    if (!arr)
        exit(1);
    stack_to_array(stack, arr, size);
    quicksort(arr, 0, size - 1);
    if (size % 2 == 0)
        median = (arr[size / 2 - 1] + arr[size / 2]) / 2;
    else
        median = arr[size / 2];
    free(arr);
    return median;
}
