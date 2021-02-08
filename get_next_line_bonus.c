/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:54:44 by amilis            #+#    #+#             */
/*   Updated: 2021/02/03 16:14:57 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		end_or_error(int ret, char *buf, char **sup_str)
{
	if (buf)
		free(buf);
	if (*sup_str)
	{
		free(*sup_str);
		*sup_str = NULL;
	}
	return (ret);
}

int		alloc_strs(char **buf, char **sup, int fd)
{
	if (!(*buf = malloc((BUFFER_SIZE) * sizeof(char))))
		return (0);
	if (sup[fd] == NULL)
	{
		if (!(sup[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (0);
		sup[fd][0] = 0;
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

int		make_line(int fd, char *buf, char **line, char **sup)
{
	int	ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1 || ret == 0)
		return (end_or_error(ret, buf, &sup[fd]));
	while (!newline_in_str(buf, ret, 1))
	{
		if (!(*line = ft_strjoin_wfree(*line, buf, ret)))
			return (end_or_error(-1, buf, &sup[fd]));
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
			return (end_or_error(ret, buf, &sup[fd]));
	}
	if (!(*line = ft_strjoin_wfree(*line, buf, ret)))
		return (end_or_error(-1, buf, &sup[fd]));
	stock_supp(buf, sup[fd], ret, 1);
	free(buf);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*sup[OPEN_MAX];
	int			ret;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(alloc_strs(&buf, sup, fd)))
		return (end_or_error(-1, buf, &sup[fd]));
	if (!(*line = ft_strdup(sup[fd])))
		return (end_or_error(-1, buf, &sup[fd]));
	if (newline_in_str(*line, 0, 0))
	{
		stock_supp(*line, sup[fd], 0, 0);
		if (!(*line = trunc_str_wfree(*line)))
			return (end_or_error(-1, buf, &sup[fd]));
		free(buf);
		return (1);
	}
	ret = make_line(fd, buf, line, sup);
	return (ret);
}
