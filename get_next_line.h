/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:19:34 by helkhouj          #+#    #+#             */
/*   Updated: 2025/01/08 14:42:50 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0 || BUFFER_SIZE > 2147483647
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*ft_memcpy(void *destination, const void *source, size_t size);
void	ft_bzero(void *ptr, size_t size);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *string);

#endif
