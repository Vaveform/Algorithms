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


