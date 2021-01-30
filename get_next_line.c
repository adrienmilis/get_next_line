/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:54:44 by amilis            #+#    #+#             */
/*   Updated: 2021/01/20 14:54:45 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(int count, int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int		alloc_strs(char **buf, char **sup)
{
	if (!(*buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (0);
	if (*sup == NULL)
	{
		if (!(*sup = malloc(sizeof(char) * BUFFER_SIZE)))
			return (0);
		*sup[0] = 0;
	}
	return (1);
}

char	*ft_strdup(const char *str)
{
	char	*str_cpy;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_strlen((char*)str);
	str_cpy = malloc((str_len + 1) * sizeof(char));
	if (str_cpy == NULL)
		return (NULL);
	while (i < str_len)
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*sup;
	int			ret;

	ret = BUFFER_SIZE;
	if (!(alloc_strs(&buf, &sup)))
		return (-1);
	if (!(*line = ft_strdup(sup)))
		return (-1);
	if (newline_in_str(*line))
	{
		stock_supp(*line, sup, ret);
		*line = trunc_str_wfree(*line);
		free(buf);
		return (1);
	}
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1 || ret == 0)
	{
		free(buf);
		return (ret);
	}
	while (!newline_in_str(buf))
	{
		*line = ft_strjoin_wfree(*line, buf, ret);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
		{
			free(buf);
			return (ret);
		}
	}
	*line = ft_strjoin_wfree(*line, buf, ret);
	stock_supp(buf, sup, ret);
	free(buf);
	return (1);
}
