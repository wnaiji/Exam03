#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int x)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	if (x == 1)
		free(str);
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2, int x)
{
	int		i;
	int		j;
	char	*tmp;
	int		len1 = ft_strlen(s1);
	int		len2 = ft_strlen(s2);

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tmp[i + j] = s2[j];
		j++;
	}
	tmp[i + j] = '\0';
	if (x == 1)
		free(s1);
	if (x == 2)
		free(s2);
	if (x == 3)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!(tmp))
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*rest;
	char		*tmp;
	int			len;
	int			i;
	static int	start = 0;

	i = 1;
	len = 0;
	tmp = NULL;
	if (fd >= 0)
	{
		if (!rest && start == 0)
		{
			while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
			{
				buf[i] = '\0';
				if (!tmp)
					tmp = ft_strdup(buf, 0);
				else
					tmp = ft_strjoin(tmp, buf, 1);
			}
			if (tmp)
				rest = ft_strdup(tmp, 1);
		}
		if (rest)
		{
			while (rest[start + len] && rest[start + len] != '\n')
				len++;
			tmp = ft_substr(rest, start, len + 1);
			start += len + 1;
			if (start - 1 == ft_strlen(rest) || start == ft_strlen(rest))
			{
				free(rest);
				rest = NULL;
			}
			return (tmp);
		}
	}
	if (rest)
	{
		free(rest);
		rest = NULL;
	}
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 5;
	if (argc == 2)
	{
		i = open(argv[1], O_RDONLY);
		while (j)
		{
			str = get_next_line(i);
			printf("%s", str);
			free(str);
			j--;
		}
		//system("leaks a.out");
	}
	return (0);
}*/
