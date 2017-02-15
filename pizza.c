#include "pizza.h"

int 	*input;
int 	*pizza;

int		main(int ac, char **av)
{
	char 	buff[1];
	int 	fd;
	int		i;
	int		k;
	char	*str;

	input = (int*)malloc(sizeof(int) * 4); // Массив інтів з індексом 0 елемент rows , 1 елемент cols , 2 мінімална кількість кожного інгредієнта, 3 максимальний 
	str = (char*)malloc(sizeof(char) * 100);
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		i = 0;
		while (buff[0] != '\n')
		{
			read(fd, buff, 1);
			str[i++] = buff[0];
		} 
		i = 0;
		k = 0;
		while (str[i] != '\n')
		{
			if (isnumber((int)str[i]) && (!(isnumber((int)str[i - 1])) || i == 0))
				input[k++] = atoi(str + i);
			i++;	
		}
		pizza = (int**)malloc(sizeof(int*) * input[0]);
		k = 0;
		while (k < input[0])
			pizza[k++] = (int*)malloc(sizeof(int) * input[1]);
		i = 0;
		while (i < input[0])
		{
			k = 0;
			while (k <= input[1])
			{
				read(fd, buff, 1);
				if (buff[0] == '\n')
					break ;
				if (buff[0] == 'M')
					pizza[i][k] = 0;
				else
					pizza[i][k] = -1;
				k++;
			}
			i++;
		}
	}
}