#include "hash_tables.h"

/**
 * make_hash_node - adasd asdsad asdas
 * @key: asd asd as dsad a
 * @value: dsa asd ada dsad asd
 *
 * Return: adad asd adasd asd ass
 */
hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *n;

	n = malloc(sizeof(hash_node_t));
	if (!n)
		return (n);
	n->key = strdup(key);
	if (!(n->key))
	{
		free(n);
		return (NULL);
	}
	n->value = strdup(value);
	if (!(n->value))
	{
		free(n->key);
		free(n);
		return (NULL);
	}
	n->next = NULL;
	return (n);
}


/**
 * hash_table_set - aasd adas dasda da dasd asdsa dasd
 * @ht: dad adasd asdsd adasd asd sad
 * @key: ad sadas dasd asdasd s
 * @value: as das asdad asdas
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	hash_node_t *hn, *t;
	char *nv;

	if (!ht || !(ht->array) || !(ht->size) || !key || !strlen(key) || !value)
		return (0);
	i = key_index((const unsigned char *)key, ht->size);
	t = ht->array[i];
	while (t != NULL)
	{
		if (!strcmp(t->key, key))
		{
			nv = strdup(value);
			if (nv == NULL)
				return (0);
			free(t->value);
			t->value = nv;
			return (1);
		}
		t = t->next;
	}
	hn = make_hash_node(key, value);
	if (!hn)
		return (0);
	hn->next = ht->array[i];
	ht->array[i] = hn;
	return (1);
}
