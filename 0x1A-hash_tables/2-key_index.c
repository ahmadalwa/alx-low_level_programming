#include "hash_tables.h"

/**
 * key_index - dassdasd
 * @key: adsadsad
 * @size: adasd asd dsadad
 *
 * Return: index for the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
