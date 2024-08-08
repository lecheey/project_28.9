#include "merge_sort.h"
#include <future>

bool make_thread = true;

void merge(int* arr, int l, int m, int r){
	int nl = m - l + 1;
	int nr = r - m;
	
	int left[nl], right[nr];

	for (int i = 0; i < nl; i++){
		left[i] = arr[l + i];
	}
	for (int j = 0; j < nr; j++){
		right[j] = arr[m + 1 + j];
	}

	int i = 0, j = 0;
	int k = l;  // начало левой части

	while (i < nl && j < nr){
		if (left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
   
	while (i < nl){
		arr[k] = left[i];
		i++;
		k++;
	}

   while (j < nr) {
       arr[k] = right[j];
       j++;
       k++;
   }
}

void mergeSort(int* arr, int l, int r){
	if(l >= r){ return; }

    int m = (l + r - 1) / 2;

	if(make_thread && (r-m > 1000)){

		std::future<void> f = std::async(std::launch::async, [&](){
			mergeSort(arr, l, m);
		});
		mergeSort(arr, m + 1, r);
		f.wait();
	
		// вариант 2 через thread, но без future 
	/*
		std::thread f (mergeSort, std::ref(arr), l, m);
		mergeSort(arr, m + 1, r);
		f.join();
	*/
    }
	else{
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
	}

	merge(arr, l, m, r);
}
