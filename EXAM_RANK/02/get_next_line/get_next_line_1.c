#include "get_next_line_1.h"

static int	ft_strlen(char *str)
{
	int count;

	if (!str)
		return (-1);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static char	*ft_strdup(char *str)
{
	char *result;
	int i;

	if (!str)
		return (NULL);
	if (!(result = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char *result;
	int i;
	int j;

	if (!s1 || !s2)
		return (NULL);
	if (!(result = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

static char	*ft_substr(char *str, int start, int length)
{
	char *result;
	int i;

	if (!str)
		return (NULL);
	if (!(result = malloc(sizeof(char) * length + 1)))
		return (NULL);
	i = 0;
	while (i < length && str[start] != '\0')
		result[i++] = str[start++];
	result[i] = '\0';
	free(str);
	return (result);
}

static int	ft_strchr(char *str, char ch)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	if (ch == '\0' && str[i] == '\0')
		return (i);
	else
		return (-1);
}

int	get_next_line(char **line)
{
	int	read_len;
	char	buff[2];
	static char *stc_buff;
	int	lf;
	char	*backup;

	while ((read_len = read(0, buff, 1)) > 0)
	{
		buff[read_len] = '\0';
		if (!stc_buff)
			stc_buff = ft_strdup(buff);
		else
			stc_buff = ft_strjoin(stc_buff, buff);
		if ((lf = ft_strchr(stc_buff, '\n')) >= 0)
		{
			backup = ft_strdup(stc_buff);
			*line = ft_substr(stc_buff, 0, lf);
			stc_buff = ft_substr(backup, lf + 1, ft_strlen(backup) - (lf + 1));
			return (1);
		}
	}
	if (read_len < 0)
		return (-1);
	else
	{
		*line = ft_strdup(stc_buff);
		free(stc_buff);
		return (0);
	}
}
