/* Test pour voir get_next_line ligne par ligne */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Ligne %d: %s", i, line);
		free(line);
		i++;
	}
	printf("\n--- Total: %d lignes lues ---\n", i - 1);
	close(fd);
	return (0);
}
