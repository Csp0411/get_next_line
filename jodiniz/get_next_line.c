/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodiniz <jodiniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:05:49 by jodiniz           #+#    #+#             */
/*   Updated: 2022/06/20 07:27:47 by jodiniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(const char *str)
{
	int		index;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\n')
		index++;
	new_str = (char *)malloc(index + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	j = 0;
	while (j < index)
	{
		new_str[j] = str[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*next_line(const char *str)
{
	int	index;

	if (!str)
		return (NULL);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return ((char *)(str + (index + 1)));
		index++;
	}
	return (NULL);
}

char	*check_line(int fd, char *str, char *buffer)
{
	int			bytes;
	char		*tmp;

	bytes = 1;
	while (!(next_line(str)) && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str, buffer);
			free(str);
			str = tmp;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	static char	*buffer_bkp;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer_bkp = check_line(fd, buffer_bkp, buffer);
	free (buffer);
	result = new_line(buffer_bkp);
	temp = ft_strdup((next_line(buffer_bkp)));
	free (buffer_bkp);
	buffer_bkp = temp;
	return (result);
}
