#include "ArraysFunctions.h"

void MatrixBubbleSort(int** arr, int ROW, int COL){
	for(int k = 0; k < ROW * COL; k++){
		int i = 0, j = 0;
		while(i * j < (COL - 1) * (ROW - 1)){
			int* tmp = &arr[i][j];
			if(j == COL - 1){
				i++;
				j = 0;
			}
			else{
				j++;
			}
			if(*tmp > arr[i][j]){
				swap(tmp, &arr[i][j]);
			}
		}
	}
}

void BubbleSort(int* array, int len){
	for(int i = 0; i < len; ++i){
		for(int j = 0; j < len - 1; ++j){
			if(array[j] > array[j + 1]){
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void InsertionSort(int* array, int len){
	for(int i = 0; i < len; ++i){
		int j = i;
		while(j > 0 && array[j - 1] > array[j]){
			swap(&array[j - 1], &array[j]);
			j--;
		}
	}
}

void ShakerSort(int* array, int len){
	// √раницы left и right можно поставить left = 0 и left = len - 2,
	// ¬ таком случае сравнение будет происходить в каждом цикле с последующим элементом
	// ћассива, а не с предыдущем, как это происходит в ниже описанном случае
	int left = 1;
	int right = len - 1;
	while(right >= left){
		for(int i = right; i >= left; i--){
			if(array[i - 1] > array[i]){     // “ам где i - 1 ставитьс€ i, а где просто i i+1 - в обоих циклах
				swap(&array[i - 1], &array[i]);
			}
		}
		left++;
		for(int i = left; i <= right; i++){
			if(array[i - 1] > array[i]){
				swap(&array[i - 1], &array[i]);
			}
		}
		right--;
	}
}

void SelectionSort(int* array, int len){
	for(int i = 0; i < len - 1; i++){
		int min_idx = i;
		for(int j = i + 1; j < len; j++){
			if(array[min_idx] > array[j]){
				min_idx = j;
			}
		}
		if(min_idx != i){
			swap(&array[min_idx], &array[i]);
		}
	}
}

void CountingSort(int* array, int len, int max_value){
	int* countings = (int*) calloc(sizeof(int) , max_value + 1);
	// Frequency analysis
	for(int i = 0; i < len; i++){
		if(array[i] < 0){
			printf("Occurred error!!!\n");
			return;
		}
		else{
			countings[array[i]] += 1;
		}
	}
	// Fill array
	int current_idx = 0;
	for(int i = 0; i < max_value + 1; i++){
		if(countings[i] == 0){
			continue;
		}
		else{
			for(int j = 1; j <= countings[i]; j++){
				array[current_idx] = i;
				current_idx += 1;
			}
		}
	}
	freeArray(countings);
}


void qs(int* array, int first, int second){
	int i = first;
	int j = second;

	int pivot = array[(first + second) / 2];

	do{
		while(array[i] < pivot){
			i++;
		}
		while(array[j] > pivot){
			j--;
		}
		if(j >= i){
			swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}while(j >= i);

	if(i < second){
		qs(array, i, second);
	}
	if(j > first){
		qs(array, first, j);
	}
}

void imprQS(int* array, int first, int second){
	// Selection sort if number of elements smaller than 11
	if(second - first < 11){
		for(int i = first; i < second; ++i){
			int j = i;
			while(j > first && array[j - 1] > array[j]){
				swap(&array[j - 1], &array[j]);
				j--;
			}
		}
	}
	// Find median of free elements and recursive QSort
	else{
		int begin = array[first];
		int median = array[(first + second) / 2];
		int end = array[second];

		// Find pivot
		if(begin > median) swap(&begin, &median);
		if(median > end) swap(&median, &end);
		if(begin > median) swap(&begin, &median);

		array[(first + second) / 2] = median;

		qs(array, first, second);

	}
}


void QSort(int* array, int len){
	int first = 0;
	int second = len - 1;
	qs(array, first, second);
}

void ImprQSort(int* array, int len){
	int first = 0;
	int second = len - 1;
	imprQS(array, first, second);
}

void bucketSort(int* arr, int len) {
    const int max = len;
    const int b = 10;

    int buckets[b][max+1];
    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }


    for (int digit = 1; digit < 1000000000; digit*=10) {
        for (int i = 0; i < max; ++i) {
            int d = (arr[i] / digit) % b;
            buckets[d][buckets[d][max]++] = arr[i];
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

