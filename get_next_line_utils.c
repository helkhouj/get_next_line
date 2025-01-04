/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:19:40 by helkhouj          #+#    #+#             */
/*   Updated: 2025/01/04 11:19:41 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		((char *)ptr)[index] = 0;
		index++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*allocated_memory;

	total_size = count * size;
	allocated_memory = malloc(total_size);
	if (allocated_memory == NULL)
		return (NULL);
	ft_bzero(allocated_memory, total_size);
	return (allocated_memory);
}

size_t	ft_strlen(char *string)
{
	size_t	length;

	if (!string)
		return (0);
	length = 0;
	while (string[length])
		length++;
	return (length);
}

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	index;

	if (!destination && !source)
		return (NULL);
	index = 0;
	while (index < size)
	{
		((char *)destination)[index] = ((char *)source)[index];
		index++;
	}
	return (destination);
}
