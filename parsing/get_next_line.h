/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:34:15 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/21 15:48:33 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1000000

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(const char *s);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dest, const void *source, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_free_and_null(char **ptr);
void	*ft_extract_line(char **stock);
int		ft_read_and_append(int fd, char **stock, char *buffer);
char	*get_next_line(int fd);

#endif
