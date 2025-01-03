#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s && s[len])
        len++;
    return len;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *joined = malloc(len1 + len2 + 1);
    if (!joined)
        return NULL;

    size_t i = 0;
    while (i < len1)
    {
        joined[i] = s1[i];
        i++;
    }

    size_t j = 0;
    while (j < len2)
    {
        joined[i] = s2[j];
        i++;
        j++;
    }
    joined[i] = '\0';
    return joined;
}

char *ft_strchr(const char *s, int c)
{
    while (s && *s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return NULL;
}

char *ft_strdup(const char *s1)
{
    size_t len = ft_strlen(s1);
    char *dup = malloc(len + 1);
    if (!dup)
        return NULL;

    size_t i = 0;
    while (i < len)
    {
        dup[i] = s1[i];
        i++;
    }
    dup[len] = '\0';
    return dup;
}
