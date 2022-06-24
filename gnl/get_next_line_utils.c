#include <stdlib.h>
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		i2;

	i = ft_strlen(s1);
	i2 = ft_strlen(s2);
	new = malloc(sizeof(char) *(i + i2 +1));
	if (!new)
		return (NULL);
	new[i + i2] = '\0';
	while (i2-- != 0)
		new[i + i2] = s2[i2];
	while (i-- != 0)
		new[i] = s1[i];
	return (new);
}
char    *ft_strchr(const char *s, int c)
{
    char    *ret;
    ret = (char *)s;
    while (*ret != (char)c)
    {
        if (*ret == '\0')
            return (0);
        ret++;
    }
    return (ret);
}
