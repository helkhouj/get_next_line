#include "get_next_line.h"
#include <stddef.h>

int	has_newline(char *buffer)
{
	size_t	index;

	if (buffer == NULL)
		return (1);
	index = 0;
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (0);
		index++;
	}
	return (1);
}

char	*append_buffer_to_line(char *current_line, char *buffer)
{
	size_t	line_length;
	size_t	buffer_index;
	size_t	new_line_index;
	char	*new_line;

	line_length = ft_strlen(current_line);
	buffer_index = 0;
	while (buffer[buffer_index] && buffer[buffer_index] != '\n')
		buffer_index++;
	new_line = (char *)ft_calloc((line_length + buffer_index + 2), sizeof(char));
	if (!new_line)
		return (free(current_line), NULL);
	new_line = ft_memcpy(new_line, current_line, line_length);
	free(current_line);
	new_line_index = 0;
	while (new_line_index <= buffer_index)
	{
		new_line[line_length + new_line_index] = buffer[new_line_index];
		new_line_index++;
	}
	line_length = ft_strlen(buffer + buffer_index);
	buffer = ft_memcpy(buffer, buffer + new_line_index, line_length);
	ft_bzero(buffer + line_length, new_line_index);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*current_line;
	ssize_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!current_line)
		return (NULL);
	current_line = append_buffer_to_line(current_line, buffer);
	if (!current_line)
		return (NULL);
	while (has_newline(current_line))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 && current_line[0])
			break ;
		if (bytes_read <= 0)
			return (free(current_line), NULL);
		current_line = append_buffer_to_line(current_line, buffer);
		if (!current_line)
			return (NULL);
	}
	return (current_line);
}
