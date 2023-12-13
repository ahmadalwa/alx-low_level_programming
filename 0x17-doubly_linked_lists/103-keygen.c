#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 * @argc: argv len
 * @argv: argv
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char pw[7], *c;
	int l = strlen(argv[1]), idx, temp;

	c = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	temp = (l ^ 59) & 63;
	pw[0] = c[temp];
	temp = 0;
	for (idx = 0; idx < l; idx++)
		temp += argv[1][idx];
	pw[1] = c[(temp ^ 79) & 63];
	temp = 1;
	for (idx = 0; idx < l; idx++)
		temp *= argv[1][idx];
	pw[2] = c[(temp ^ 85) & 63];
	temp = 0;
	for (idx = 0; idx < l; idx++)
	{
		if (argv[1][idx] > temp)
			temp = argv[1][idx];
	}
	srand(temp ^ 14);
	pw[3] = c[rand() & 63];
	temp = 0;
	for (idx = 0; idx < l; idx++)
		temp += (argv[1][idx] * argv[1][idx]);
	pw[4] = c[(temp ^ 239) & 63];

	for (idx = 0; idx < argv[1][0]; idx++)
		temp = rand();
	pw[5] = c[(temp ^ 229) & 63];
	pw[6] = '\0';
	printf("%s", pw);
	return (0);
}
