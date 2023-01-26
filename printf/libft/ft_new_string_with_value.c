/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_string_with_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:14:45 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/18 16:16:48 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_string_with_value(char *value)
{
	char	*new_string;
	int		strlen;

	strlen = ft_strlen(value);
	new_string = ft_new_string(strlen + 1);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, value, strlen + 1);
	return (new_string);
}
