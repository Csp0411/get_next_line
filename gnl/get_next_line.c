#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#define GREY "\033[1;93m" 
#define END "\033[0;0m"
char	*ft_strjoin(char const *s1, char const *s2);

char *get_next_line(int fd);

char    *ft_strchr(const char *s, int c);

int count(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] != '\n' && buffer[i] != 0)
    {
        i++;
        if (buffer[i] == '\0')
        {
//            printf("ft_count %d", i);
            return (-1);
        }
    }
    return(i + 1);
}

char	*ft_free(char *str)
{
	char	*temp;

	temp = str;
	free (str);
	str = temp;
	return (str);
}

char *ft_buffer(char *buffer, char *save, int k)
{
    int i;
    char    *line;
    char    *buffer2;


	buffer2 = ft_strjoin(save, buffer);
//    printf("%s ", buffer2);
	i = count(buffer2);
//	k = ft_test_null(buffer2);
    if (k == 0)
    {
		if (i <= 0)
            return ((void *)0);
        line = (char *)malloc((i +1) * sizeof(char));
		if (!line)
		{
			free (line);
			free (buffer2);
			return (NULL);
		}
		line[i] = '\0';
//        printf("valor = %d\n", i);
//        printf("%s\n", buffer2);
        while (buffer2[k] != '\n' && buffer2[k] != '\0')
        {
            line[k] = buffer2[k];
//            printf ("k = %d e %c\n",i, linha[i]);
            k++;
        }
        line[k] = '\n';
//        printf("%s", linha);
		free (buffer2);
        return (line);
    }
	else
	{
		if (i < 0)
		{
            return (buffer2);
		}
        save = ft_strchr(buffer2, '\n');
        free(buffer2);
		save++;
        return (save);
    }
}

char *get_next_line(int fd)
{
    char    *buffer;
    static char *save;
    int         ret_read;
    char    *line;

    if (!save)
        save = "";
 //   repet = test(save);
 //   ret_read = read(fd, buffer, BUFFER_SIZE);
    line = NULL;
    while (line == NULL)
    {
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
        ret_read = read(fd, buffer, BUFFER_SIZE);
//        printf(GREY "\nretorno = %d e buffer =%srio"END,ret_read, buffer);
		buffer[ret_read] = '\0';
/*		if (ret_read == 0)
		{
			free (buffer);
			line = save;
			save = NULL;
			return (line);
		}*/
		if (ret_read <= 0)
		{
//			printf("1 if\n");
			free (buffer);
			return (NULL);
		}
        line = ft_buffer(buffer, save, 0);
//        printf("linha: %s",line);
        save = ft_buffer(buffer, save, 1);
//        printf("sa: %s\n", save);
		free (buffer);
    }
	return (line);
}
