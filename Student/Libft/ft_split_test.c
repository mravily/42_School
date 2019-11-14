#include "libft.h"

static char	**ft_wrdcount(char const *s, char c)
{
	int		i;
	int		inwrd;
	int		wc;
	char	**strtab;

	i = 0;
	wc = 0;
	inwrd = 0;
	while (s[i])
	{
		if (s[i] == c)
			inwrd = 0;
		else if (!inwrd)
		{
			wc++;
			inwrd = 1;
		}
		i++;
	}
	if (!(strtab = malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	strtab[wc] = NULL;
	return (strtab);
}

static int		ft_wrdcpy(char const *s, char c, char **p, int j)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(p[j] = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		p[j][i] = s[i];
		i++;
	}
	p[j][i] = '\0';
	return (1);
}

static char	**ft_splitter(char const *s, char c, char **strtab)
{
	int i;
	int j;
	int inwrd;

	i = 0;
	j = 0;
	inwrd = 0;
	while (s[i])
	{
		if (s[i] == c)
			inwrd = 0;
		else if (!inwrd)
		{
			inwrd = 1;
			if (!ft_wrdcpy(s + i, c, strtab, j))
				return (NULL);
			j++;
		}
		i++;
	}
	return (strtab);
}

char		**ft_split(char const *s, char c)
{
	char	**strtab;

	if (!s)
		return (NULL);
	if (!(strtab = ft_wrdcount(s, c)))
		return (NULL);
	if (!(strtab = ft_splitter(s, c, strtab)))
		return (NULL);
	return (strtab);
}

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(void)
{
	char	**str2;
	char const *s = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";
	int		j;
	j = 0;
	if (!(str2 = ft_split(s, 'i')))
		ft_print_result("NULL");
	else
	{
		while (str2[j] != '\0')
		{
			ft_print_result(str2[j]);
			write(1, "\n", 1);
			j++;
		}
	}
}