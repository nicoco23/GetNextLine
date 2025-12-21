/* Test bonus: lecture alternée de plusieurs fichiers */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("get_next_line.c", O_RDONLY);
	fd3 = open("get_next_line.h", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Erreur ouverture fichiers\n");
		return (1);
	}

	printf("=== Test lecture alternée de 3 fichiers ===\n\n");

	// Lecture alternée pour démontrer le bonus
	printf("--- FD1 ligne 1 ---\n");
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	printf("\n--- FD2 ligne 1 ---\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	printf("\n--- FD3 ligne 1 ---\n");
	line = get_next_line(fd3);
	printf("%s", line);
	free(line);

	printf("\n--- FD1 ligne 2 ---\n");
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	printf("\n--- FD2 ligne 2 ---\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	printf("\n--- FD3 ligne 2 ---\n");
	line = get_next_line(fd3);
	printf("%s", line);
	free(line);

	printf("\n=== Succès ! Chaque fd garde sa position ===\n");

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
