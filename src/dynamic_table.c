#include "../include/dynamic_table.h"

// typedef struct DynamicTable {
    
//  long int size_;
//  long int  capacity_;
//  float factor_;
//  int *arr_;
    
// }DynamicTable;

// DynamicTable *init(long int  capacity, float factor_);
// void push_back(DynamicTable *Table, int value);
// void remove_element(DynamicTable *Table);
// void resize_(DynamicTable *Table, int amount);
// void delete_table(DynamicTable *Table);

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

    // Create extra space if full
    if(Table->size_ == Table->capacity_ - 1) {
        resize_(Table, (Table->capacity_*Table->factor_));
    }
    
    // Push element
    Table->arr_[Table->size_] = value;
    ++Table->size_;
}

void remove_element(DynamicTable *Table) {
    if(Table->size_ == 0) { // Check for no elements
        return;
    }
    
    Table->size_--; //Pop last element
    
    // Resize if ratio of capacity to size exceeds the factor
    if(Table->capacity_/Table->size_ > Table->factor_ && Table->capacity_ > 100) {
        resize_(Table, Table->capacity_/Table->factor_);
    }
}

void resize_(DynamicTable *Table, int amount) {
    
    if(Table->capacity_ > amount) { // Reduce
        Table->arr_ = realloc(Table->arr_, sizeof(int)*amount);
    }
    
    else {  //Increase
        int *new_arr = malloc(sizeof(int)*amount), i; // Create new space
        
        for(i = 0; i < Table->size_; i++) {
            new_arr[i] = Table->arr_[i];
        }
        
        // Delete old space
        free(Table->arr_);

        // Assign the newly allocated space
        Table->arr_ = new_arr;
    }
    
    // Update with new capacity
    Table->capacity_ = amount;
}

void delete_table(DynamicTable *Table) {
    
    free(Table->arr_);
    free(Table);
}