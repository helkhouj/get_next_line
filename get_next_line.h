#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
void	*ft_memcpy(void *destination, const void *source, size_t size);
void	ft_bzero(void *ptr, size_t size);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *string);

#endif
