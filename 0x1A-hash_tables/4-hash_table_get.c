#include "hash_tables.h"

/**
 * hash_table_get - dadasd asda dasda sd
 * @ht: das ad asdsa sdadsa das
 * @key: ad asdsa dad asda dasd ad
 *
 * Return: adasda sd adsd asd,a djkasdj ajkdhasjkdh kjsad kas
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i;
	hash_node_t *t;

	if (!ht || !(ht->array) || !(ht->size) || !key || !strlen(key))
		return (NULL);
	i = key_index((const unsigned char *)key, ht->size);
	t = ht->array[i];
	while (t)
	{
		if (strcmp(t->key, key) == 0)
			return (t->value);
		t = t->next;
	}
	return (NULL);
}
