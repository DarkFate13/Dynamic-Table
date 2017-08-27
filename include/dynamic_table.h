#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DynamicTable {
	
	long int size_;
	long int  capacity_;
	float factor_;
	int *arr_;
	
}DynamicTable;

DynamicTable *init(long int  capacity, float factor_);
void push_back(DynamicTable *Table, int value);
void remove_element(DynamicTable *Table);
void resize_(DynamicTable *Table, int amount);
void delete_table(DynamicTable *Table);