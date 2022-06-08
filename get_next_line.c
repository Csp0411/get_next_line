/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilveir <csilveir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:46:37 by csilveir          #+#    #+#             */
/*   Updated: 2022/06/08 15:58:18 by csilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define GREY "\033[1;93m" 
#define END "\033[0;0m"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (*ret != (char)c)
	{
		if (*ret == '\0')
			return (0);
		ret++;
	}
	return (ret);
}

static char	*ft_buffer(char	*buffer)
{
	static char	*save;
//	char	*ret;
//	int i;
//	int j;

//	i = 0;
//	j = 0;

	printf("rio");
	if ()
	{
		save = ft_strchr(buffer, '\n');
		printf("if nao tiver quebra de linha->%s",save);
	//	free(buffer);
	}
/*	else
	{
		printf("rio");
		while (buffer[i] != 10)
			i++;
		i++;
		while (i <= BUFFER_SIZE)
			save[j++] = buffer[i++];
		save[j] = '\0';
		printf("%s\n", save);
	}	*/
	return (buffer);
}

char *get_next_line(int fd)
{
//	static char	*content;
//	char		*str;
	char		*buffer;
	int			ret_read;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	ret_read = read(fd, buffer, BUFFER_SIZE);
	printf(GREY "retorno = %d e buffer =%s\n"END,ret_read, buffer);
	buffer = ft_buffer(buffer);
	return (buffer);
}

