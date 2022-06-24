#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define CIANO "\033[194m" 
char *get_next_line(int fd);

int main(void)
{
	int fd = open("41_no_nl.txt", O_RDONLY);
/*	int fd1 = open("example3.txt", O_RDONLY);
	int fd2 = open("example5.txt", O_RDONLY);
	int fd3 = open("example4.txt", O_RDONLY);
	int fd4 = open("nl.txt", O_RDONLY);*/

	char	*line;
/*	char	*line1;
	char	*line2;
	char	*line3;
	char	*line4;

	line = get_next_line(fd);
	printf(CIANO"\nMAN ->%s\n", line);*/

	int i = 1;
	printf("Texto null\n\n");
	while((line = get_next_line(fd)))
		printf("\033[0;37m%iº\033[0m %s", i++, line);
	printf("________________________________________________________________________________\n\n");/*
	printf("Texto aleatório normal\n\n");
	while((line = get_next_line(fd)))
		printf("\033[0;37m%iº\033[0m %s", i++, line);
	printf("________________________________________________________________________________\n\n");
	i = 1;
	printf("Texto vazio\n\n");
	while((line1 = get_next_line(fd1)))
		printf("\033[0;37m%iº\033[0m %s", i++, line1);
	printf("________________________________________________________________________________\n\n");
	i = 1;
	printf("Texto com quebras de linha seguidas\n\n");
	while((line2 = get_next_line(fd2)))
		printf("\033[0;37m%iº\033[0m %s", i++, line2);
	printf("________________________________________________________________________________\n\n");
	i = 1;
	printf("Texto com apenas uma linha grande\n\n");
	while((line3 = get_next_line(fd3)))
		printf("\033[0;37m%iº\033[0m %s", i++, line3);*/
	return 0;
}

