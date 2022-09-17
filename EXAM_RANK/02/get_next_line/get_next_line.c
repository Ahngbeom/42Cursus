#include "get_next_line.h"
int	ft_strlen(char *str)
{
	int count;

	if (!str)
		return (-1);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	char *result;
	int i;

	if (!str)
		return (NULL);
	if(!(result = malloc(sizeof(char) * ft_strlen(str) + 1)))
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

char	*ft_strjoin(char *s1, char *s2)
{
	char *result;
	int i;
	int j;

	if (!s1 || !s2)
		return (NULL);
	if (!(result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
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

char	*ft_substr(char *str, int start, int end)
{
	char *result;
	int i;

	if (!str)
		return (NULL);
	if(!(result = malloc(sizeof(char) * (end - start) + 1)))
		return (NULL);
	i = 0;
	while (i < end && str[start] != '\0')
	{
		result[i++] = str[start++];
	}
	free(str);
	result[i] = '\0';
	return (result);
}

int	ft_strchr(char *str, char ch)
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
	return (-1);
}

int	get_next_line(char **line)
{
	int	read_val;
	char	*buff;
	static char *stc_buff;
	char	*backup;
	int	lf;

	if (!(buff = malloc(sizeof(char) * 2)))
		return (-1);
	while ((read_val = read(0, buff, 1)) > 0)
	{
		buff[read_val] = '\0';
		if (!stc_buff)
			stc_buff = ft_strdup(buff);
		else
			stc_buff = ft_strjoin(stc_buff, buff);
		if ((lf = ft_strchr(stc_buff, '\n')) >= 0)
		{
			free(buff);
			backup = ft_strdup(stc_buff);
			*line = ft_substr(stc_buff, 0, lf);
			stc_buff = ft_substr(backup, lf + 1, ft_strlen(backup));
			return (1);
		}
	}
	free(buff);
	if (read_val < 0)
		return (-1);
	else
	{
		*line = ft_strdup(stc_buff);
		free(stc_buff);
		return (0);
	}
}
