#include "hash_tables.h"

/**
 * hash_table_delete - da asd adsas d
 * @ht: dad ada sdasd
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *n;
	unsigned long int i;

	if (!ht || !(ht->array) || !(ht->size))
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i])
		{
			n = ht->array[i]->next;
			free(ht->array[i]->value);
			free(ht->array[i]->key);
			free(ht->array[i]);
			ht->array[i] = n;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
