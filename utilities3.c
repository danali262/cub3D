#include "cub3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	n;

	i = 0;
	while (s[i] != '\0')
	{
		n = write(fd, &s[i], 1);
		if (n < 0)
			return ;
		i++;
	}
}

int	ft_ismapchar(int c)
{
	if (c != '0' && c != '1' && c != '2' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'E')
		return (0);
	return (1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = NULL;
	ptr = (unsigned char *)b;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}

static char	*ft_fill(char *src, char *append, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (append[j] != '\0')
	{
		dest[i] = append[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *src, char *append)
{
	int		x;
	char	*dest;

	x = ft_strlen(src) + ft_strlen(append);
	dest = (char *)malloc(sizeof(char) * (x + 1));
	if (!dest)
	{
		free(append);
		free(src);
		return (0);
	}
	dest = ft_fill(src, append, dest);
	free(append);
	free(src);
	return (dest);
}
