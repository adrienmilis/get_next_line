/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:54:49 by amilis            #+#    #+#             */
/*   Updated: 2021/02/03 16:15:03 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

unsigned long	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*trunc_str_wfree(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (!(new_str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	new_str[i] = '\0';
	return (new_str);
}

void			stock_supp(const char *str, char *sup, int nb_car)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && i < nb_car)
		i++;
	i++;
	while (i < nb_car && str[i])
	{
		sup[j] = str[i];
		j++;
		i++;
	}
	sup[j] = '\0';
}

char			*ft_strjoin_wfree(char *str, char *buf, int nb_car)
{
	char	*str_cat;
	int		i;
	int		j;

	if (str == NULL || buf == NULL)
		return (NULL);
	if (!(str_cat = malloc((ft_strlen(str) + nb_car + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
		str_cat[i++] = str[j++];
	free(str);
	j = 0;
	while (j < nb_car && buf[j] != '\n')
		str_cat[i++] = buf[j++];
	str_cat[i] = '\0';
	return (str_cat);
}

int				newline_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
