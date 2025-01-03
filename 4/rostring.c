// Write a program that takes a string and displays this string after rotating it
// one word to the left.
// 
// Thus, the first word becomes the last, and others stay in the same order.
// 
// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.
// 
// Words will be separated by only one space in the output.
// 
// If there's less than one argument, the program displays \n.

#include <unistd.h>
int	main(int argc, char *argv[])
{
	int i = 0;
	int start = 0;
	int end = 0;

	if (argc == 2)
	{
		while(argv[1][start] && argv[1][start] == ' ')
			start++;
		end = start;
		while(argv[1][end] && argv[1][end] != ' ')
			end++;
		i = end;
		while (argv[1][i])
		{
			while(argv[1][i] && argv[1][i] == ' ')
				i++;
			while(argv[1][i] && argv[1][i] != ' ')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			if (!argv[1][i])
				break ;
			write(1, " ", 1);
		}
		while (start < end)
			write(1, &argv[1][start++], 1);
	}
	write(1, "\n", 1);
}