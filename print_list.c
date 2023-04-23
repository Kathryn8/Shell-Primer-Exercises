#include <stddef.h>
#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints the data in linked list node
 * @h: data type list_t is a struct list_s, node of linked list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t size = 0;
	const list_t *temp = h;

	while (temp != NULL)
	{
		if (temp->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%i] %s\n", temp->len, temp->str);
		}
		temp = temp->next;
		size = size + 1;
	}
	return (size);
}
