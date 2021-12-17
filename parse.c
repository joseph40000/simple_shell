#include "allhead.h"

/**
  * parse_input_string - splits the string entered by the user.
  * @buffer: string to be split.
  * Return: splitted string.
  */
char **parse_input_string(char *buffer)
{
	char **cd = NULL;
	char *token, *delimeter = " \n";
	int i;

	cd = malloc(sizeof(char *) * 1024);
	if (cd == NULL)
	{
		perror("couldn't allocate memory");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delimeter);
	i = 0;

	while (token != NULL)
	{
		cd[i] = token;
		token = strtok(NULL, delimeter);
		i++;
	}
	cd[i] = NULL;
	return (cd);
}

