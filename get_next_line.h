/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:54:38 by amilis            #+#    #+#             */
/*   Updated: 2021/01/20 14:54:40 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // a enlever

void			*ft_calloc(int count, int size);
int				alloc_strs(char **buf, char **sup);
char			*ft_strdup(const char *str);
int				make_line(int fd, char *buf, char **line, char *sup);
int				get_next_line(int fd, char **line);
unsigned long	ft_strlen(char *str);
char			*trunc_str_wfree(char *str);
void			stock_supp(const char *str, char *sup, int nb_car);
char			*ft_strjoin_wfree(char *str, char *buf, int nb_car);
int				newline_in_str(char *str);

#endif
