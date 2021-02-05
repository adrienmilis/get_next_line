/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:15:23 by amilis            #+#    #+#             */
/*   Updated: 2021/02/03 16:15:24 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void			*ft_calloc(int count, int size);
int				alloc_strs(char **buf, char **sup, int fd);
char			*ft_strdup(const char *str);
int				make_line(int fd, char *buf, char **line, char **sup);
int				get_next_line(int fd, char **line);
unsigned long	ft_strlen(char *str);
char			*trunc_str_wfree(char *str);
void			stock_supp(const char *str, char *sup, int nb_car, int mode);
char			*ft_strjoin_wfree(char *str, char *buf, int nb_car);
int				newline_in_str(char *str, int nb_car, int mode);

#endif
