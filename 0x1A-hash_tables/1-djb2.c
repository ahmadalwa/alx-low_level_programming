#include "hash_tables.h"

/**
 * hash_djb2 - asdasdsa
 * @str: asdasdsad sdfsf
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int h;
	int i;

	h = 5381;
	while ((i = *str++))
		h = ((h << 5) + h) + i;
	return (h);
}
