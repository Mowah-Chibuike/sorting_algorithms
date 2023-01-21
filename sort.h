#ifndef SORT_H
#define SORT_H

#include "structs.h"
#include <stddef.h>

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif /* SORT_H */
