#include "../include/dynamic_table.h"

// typedef struct DynamicTable {
	// size_t size_;
	// size_t capacity_;
	// int factor_;
	// int *arr_;
// }DynamicTable;

// DynamicTable *init(size_t size = 0, size_t capacity = 100, int factor_ = 2);
// bool push_back(DynamicTable *Table, int value);
// bool remove(DynamicTable *Table);
// void resize_(DynamicTable *Table, int factor);

DynamicTable *init(long int capacity, float factor) {
	DynamicTable *Table = malloc(sizeof(DynamicTable));
	
	if (!Table) {
		printf("Error initialising table!");
		return NULL;
	}
	
	Table->size_ = 0;
	Table->capacity_ = capacity;
	Table->factor_ = factor;
	Table->arr_ = malloc(sizeof(int) * capacity);
	
	return Table;
	
}

void push_back(DynamicTable *Table, int value) {
	if(Table->size_ == Table->capacity_ - 1) {
		resize_(Table, (Table->capacity_*Table->factor_));
	}
	
	Table->arr_[Table->size_] = value;
	++Table->size_;
}

void remove_element(DynamicTable *Table) {
	if(Table->size_ == 0) {
		return;
	}
	
	Table->size_--;
	
	if(Table->capacity_/Table->size_ > Table->factor_ && Table->capacity_ > 100) {
		resize_(Table, Table->capacity_/Table->factor_);
	}
}

void resize_(DynamicTable *Table, int amount) {
	
	if(Table->capacity_ > amount) { // Reduce
		Table->arr_ = realloc(Table->arr_, sizeof(int)*amount);
	}
	
	else {	//Increase
		int *new_arr = malloc(sizeof(int)*amount), i;
		
		for(i = 0; i < Table->size_; i++) {
			new_arr[i] = Table->arr_[i];
		}
		
		free(Table->arr_);
		Table->arr_ = new_arr;
	}
	
	Table->capacity_ = amount;
}

void delete_table(DynamicTable *Table) {
	
	free(Table->arr_);
	free(Table);
}