#include "../include/utils.h"

void swap(long int *num1, long int *num2) {
    long int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

bool *create_data(long int insert_times, long int delete_times) {
    
    long int i = 0;
    
    if(delete_times > insert_times) {
        swap(&delete_times, &insert_times);
    }
    
    bool *arr = malloc(sizeof(bool) * (insert_times + delete_times));
    
    for(i = 0; i < insert_times; i++) {
        arr[i] = 1;
    }
    
    for(; i < delete_times; i++) {
        arr[i] = 0;
    }
    
    randomize(arr, (insert_times + delete_times));
    return arr;
    
}

void randomize (bool arr[], long int n) {
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand (time(NULL));
    long int i;
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (i = n-1; i > 0; i--) {
        // Pick a random index from 0 to i
        long int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
    
    return;
}
