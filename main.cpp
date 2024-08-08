#include <iostream>
#include <random>
#include <chrono>
#include "merge_sort.h"

int main(){
	srand(0);
	long arr_size = 2000000;
	int* array = new int[arr_size];
	for(long i=0;i<arr_size; i++) {
		array[i] = rand() % 500000;
	}

	time_t start, end;

	time(&start);
	mergeSort(array, 0, arr_size);
	time(&end);

	double seconds = difftime(end, start);
	printf("The time: %f seconds\n", seconds);

	return 0;
}
