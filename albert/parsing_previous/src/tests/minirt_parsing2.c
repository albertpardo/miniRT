#include "minirt.h"

void	putarraystr(char **arrstr)
{
	ft_printf("\nArray de strings de la linea sin extra spaces: \n");
	while (arrstr && *arrstr)
	{
		ft_printf("%s\n", *arrstr);
		arrstr++;
	}
}

static void exitifemptyfileoronlyspaces(int i, int j)
{
	if (i == 0)
		exiterror(EMPTY_FILE);
	else if (j == 0)
		exiterror(SPACES_IN_FILE);
}

/*
 *
 * - i : counter for total file lines
 * - j : counter for no lines equal to "\0" or "\n"
 */

int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	char	*cleanstr;
	char 	**splitline;
	int		i;
	int		j;

	if (argc == 2)
	{
		i = 0;
		j = 0;
		exitifnotvalidfiletype(argv[1], EXT, BAD_FILETYPE);
		fd = open(argv[1], O_RDONLY);
		exitifcheckfails(fd, NO_OPEN);
		line = get_next_line(fd);
  		while (line)
		{
			i++;
			cleanstr = cleanstringspaces(line);
			if (cleanstr[0] != '\0' && cleanstr[0] != '\n')
				j++;
			ft_printf("--------------------------------------------\n");
			ft_printf("Linea Original  >%s", line);
			ft_printf("Del extra spaces>%s", cleanstr);
			splitline = ft_split(cleanstr, ' ');
			putarraystr(splitline);
			checkidvalid(splitline);
			freearrstr(splitline);
			free(cleanstr);
			free(line);
			line = get_next_line(fd);
		}
		exitifcheckfails(close(fd), NO_CLOSE);
		exitifemptyfileoronlyspaces(i, j);
	}
	else
		exiterror(BAD_ARGUMENTS);
	return (0);
}