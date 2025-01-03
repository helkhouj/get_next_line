#include "get_next_line.h"

static char *extract_line(char **buffer)
{
    char *newline_pos = ft_strchr(*buffer, '\n');
    char *line;
    char *temp;

    if (newline_pos)
    {
        size_t len = newline_pos - *buffer + 1;
        line = malloc(len + 1);
        if (!line)
            return NULL;
        size_t i = 0;
        while (i < len)
        {
            line[i] = (*buffer)[i];
            i++;
        }
        line[len] = '\0';
        temp = ft_strdup(newline_pos + 1);
        if (!temp)
        {
            free(line);
            return NULL;
        }
        free(*buffer);
        *buffer = temp;
    }
    else
    {
        line = ft_strdup(*buffer);
        if (!line)
            return NULL;
        free(*buffer);
        *buffer = NULL;
    }
    return line;
}

static int read_to_buffer(int fd, char **buffer)
{
    char temp_buf[BUFFER_SIZE + 1];
    char *new_buffer;
    int bytes_read;

    while ((bytes_read = read(fd, temp_buf, BUFFER_SIZE)) > 0)
    {
        temp_buf[bytes_read] = '\0';
        new_buffer = ft_strjoin(*buffer, temp_buf);
        if (!new_buffer)
        {
            free(*buffer);
            return -1;
        }
        free(*buffer);
        *buffer = new_buffer;
        if (ft_strchr(temp_buf, '\n'))
            break;
    }
    return bytes_read;
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    if (!buffer)
    {
        buffer = ft_strdup("");
        if (!buffer)
            return NULL;
    }

    if (read_to_buffer(fd, &buffer) < 0)
    {
        free(buffer);
        buffer = NULL;
        return NULL;
    }

    if (!buffer || *buffer == '\0')
    {
        free(buffer);
        buffer = NULL;
        return NULL;
    }

    line = extract_line(&buffer);
    if (!line)
    {
        free(buffer);
        buffer = NULL;
    }
    return line;
}
