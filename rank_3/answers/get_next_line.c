#include "get_next_line.h"

char	*get_next_line(int fd);
char	*fill_storage(int fd, char *storage);
char	*get_line(char *s);
char	*update_storage(char *s);

int		has_newline(char *s);
char	*merge_strs(char *s, char *b);
int		strclen(char *s, char c);
void	append_str(char *dst, char *src, int len);

/*
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
*/

char *get_next_line(int fd)
{
	char *line;
	static char *storage;

	storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	if (!*line)
	{
		free(line);
		free(storage);
		return (NULL);
	}
	storage = update_storage(storage);
	return (line);
}

char	*fill_storage(int fd, char *storage)
{
	int bytes = 1;
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes != 0 && has_newline(storage) == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		storage = merge_strs(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_line(char *s)
{
	int l_nwl = strclen(s, '\n');
	if (s[l_nwl] == '\n')
		l_nwl++;
	char *line = malloc(sizeof(char) * (l_nwl + 1));
	if (!line)
		return (NULL);
	append_str(line, s, l_nwl);
	return (line);
}

char	*update_storage(char *s)
{
	int l_nwl = strclen(s, '\n');
	int l_nul = strclen(s, '\0');
	if (s[l_nwl] == '\n')
		l_nwl++;
	char *new = malloc(sizeof(char) * (l_nul - l_nwl + 1));
	if (!new)
		return (NULL);
	append_str(new, s + l_nwl, l_nul - l_nwl + 1);
	free(s);
	return (new);
}

// UTILS -----------------------------------------------------------------------

int	has_newline(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		strclen(char *s, char c)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	append_str(char *dst, char *src, int len)
{
	int i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*merge_strs(char *s, char *b)
{
	int l1 = strclen(s, '\0');
	int l2 = strclen(b, '\0');

	char *new = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!new)
		return (NULL);
	if (s)
		append_str(new, s, l1);
	append_str(new + l1, b, l2);
	new[l1 + l2] = '\0';
	if (s)
		free(s);
	return (new);
}
