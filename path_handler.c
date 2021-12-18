#include "allhead.h"

/**
  * *path_search - makes a complete path from path.
  * @cmd: command to make complete path from.
  * Return: complete path.
  */
char *path_search(char *cmd)
{
	char *path = NULL, *token = NULL, ch = '/';
	char *dirs[1024];
	int i;
	char *cwd = getcwd(NULL, 0);
	struct stat sb;

	path = getenv("PATH");
	token = strtok(path, ":");
	if (dirs == NULL)
	i = 0;
	while (token != NULL)
	{
		dirs[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	dirs[i] = NULL;

	i = 0;
	while (dirs[i] != NULL)
	{
		chdir(dirs[i]);
		if (stat(cmd, &sb) == 0)
		{
			dirs[i] = _strncat(dirs[i], &ch, 1);
			cmd = _strcat(dirs[i], cmd);
			break;
		}
		i++;
	}
	chdir(cwd);
	return (cmd);
}



/**
 *_strncat - concatenates two strings.
 *
 * @dest: resulting string.
 * @src: source string.
 * @n: string length.
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, m;

	m = string_length(dest);
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[m + i] = src[i];
	}
	dest[m + i] = '\0';
	return (dest);
}

