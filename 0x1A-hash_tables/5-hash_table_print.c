#include "hash_tables.h"

/**
 * hash_table_print - dasd asdsada dasd asd
 * @ht: ad asd sadsad adas d
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	char f = 0;
	hash_node_t *t;

	if (!ht || !(ht->array))
		return;
	printf("%s", "{");
	for (i = 0; i < ht->size; i++)
	{
		t = ht->array[i];
		while (t)
		{
			if (f == 1)
			{
				printf(", ");
			}
			printf("'%s': '%s'", t->key, t->value);
			t = t->next;
			f = 1;
		}
	}
	printf("%s", "}\n");
}
