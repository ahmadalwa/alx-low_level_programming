#include "hash_tables.h"

/**
 * shash_table_create - dasd ada dsda dsada sds
 * @size: dad adsada dasd asd asdads
 *
 * Return: dadasd asdasd asd asdasd asd
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *sss;

	sss = malloc(sizeof(shash_table_t));
	if (!sss)
		return (NULL);
	sss->size = size;
	sss->stail = NULL;
	sss->shead = NULL;
	sss->array = malloc(sizeof(shash_node_t) * size);
	if (!(sss->array))
	{
		free(sss);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		sss->array[i] = NULL;
	return (sss);
}

/**
 * make_shash_node - d adasd adas dad a
 * @key: d adsad asdsad sad asd
 * @value: sdf sdfsdf sd fsdfd s
 *
 * Return: fdsfsd fsdfsd fds fsfdsfsdfsd
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *sss;

	sss = malloc(sizeof(shash_node_t));
	if (!sss)
		return (NULL);
	sss->key = strdup(key);
	if (!(sss->key))
	{
		free(sss);
		return (NULL);
	}
	sss->value = strdup(value);
	if (!(sss->value))
	{
		free(sss->key);
		free(sss);
		return (NULL);
	}
	sss->next = sss->snext = sss->sprev = NULL;
	return (sss);
}

/**
 * add_to_sorted_list - dad asds dad asdasd
 * @table: d ads sadsad asdasdsa
 * @node: d adasdad asdasd asdasd
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *t;

	if (!(table->shead) && !(table->stail))
	{
		table->shead = table->stail = node;
		return;
	}
	t = table->shead;
	while (t)
	{
		if (strcmp(node->key, t->key) < 0)
		{
			node->snext = t;
			node->sprev = t->sprev;
			t->sprev = node;
			if (node->sprev)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		t = t->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sdf sfsd fsdf sdf
 * @ht: s fsd fsdf sdfsf sd
 * @key: f sdfsd fsdf s
 * @value: s dfsdf sdf
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	shash_node_t *sss, *t;
	char *nv;

	if (!ht || !(ht->array) || !(ht->size) || !key || !strlen(key) || !value)
		return (0);
	i = key_index((const unsigned char *)key, ht->size);
	t = ht->array[i];
	while (t)
	{
		if (!strcmp(t->key, key))
		{
			nv = strdup(value);
			if (!nv)
				return (0);
			free(t->value);
			t->value = nv;
			return (1);
		}
		t = t->next;
	}
	sss = make_shash_node(key, value);
	if (!sss)
		return (0);
	sss->next = ht->array[i];
	ht->array[i] = sss;
	add_to_sorted_list(ht, sss);
	return (1);
}

/**
 * shash_table_get - sdf sdfds fsdf dsf
 * @ht: s fsd fsdf sd
 * @key: s fsdf sdfsd
 *
 * Return:  sfsdf sdf sdfsd
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *t;
	unsigned long int i;

	if (!ht || !(ht->array) || !(ht->size) || !key || !(strlen(key)))
		return (NULL);
	i = key_index((const unsigned char *)key, ht->size);
	t = ht->array[i];
	while (t)
	{
		if (!(strcmp(t->key, key)))
			return (t->value);
		t = t->next;
	}
	return (NULL);
}

/**
 * shash_table_print - dasd asdsa dad asdsad ad
 * @ht: da sdasd sad asd
 */
void shash_table_print(const shash_table_t *ht)
{
	char flag = 0;
	shash_node_t *t;

	if (!ht || !(ht->array))
		return;
	printf("{");
	t = ht->shead;
	while (t)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", t->key, t->value);
		t = t->snext;
		flag = 1;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - ada dsa dasd ada ds
 * @ht: dad asdsa dasd asd
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	char flag = 0;
	shash_node_t *t;

	if (!ht || !(ht->array))
		return;
	printf("{");
	t = ht->stail;
	while (t)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", t->key, t->value);
		t = t->sprev;
		flag = 1;
	}
	printf("}\n");
}

/**
 * shash_table_delete - adsadasd ad asd asda
 * @ht: ad ads adsa dsad
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *n;

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
	ht->stail = NULL;
	ht->shead = NULL;
	ht->size = 0;
	free(ht);
}
