#include "ArraysFunctions.h"

int searchNum(int* array, int len, int value) {
    for (int i = 0; i < len; ++i) {
        if (array[i] == value)
            return i;
    }
    return -1;
}

float mean(int* array, int len) {
    float sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += array[i];
    }
    return sum / len;
}

int** initArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}

void fillArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            scanf("%d", &(*((*(array + i)) + j)));
        }
    }
}

void printArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%4d", *((*(array + i)) + j));
        }
        printf("\n");
    }
}

void changeCols(int** array, int row, int col, int from, int to) {
    char temp;
    for (int i = 0; i < row; ++i) {
        temp = *((*(array + i)) + from);
        *((*(array + i)) + from) = *((*(array + i)) + to);
        *((*(array + i)) + to) = temp;
    }
}

void swap(int* left, int* right){
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

void freeMatrix(int** array, const int row){
	for(int i = 0; i < row; i++){
		free(array[i]);
	}
	free(array);
}

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


double MathFunc(double value){
	return sqrt(fabs(value)) + 5 * pow(value, 3);
}


void TrabbPradoKnuthAlgorithm(double (*Func) (double)){
	printf("Input 11 numbers:\n");
	const int size= 11;
	double array[size], val;
	for(int i = 0; i < size; i++){
		scanf("%lf", &array[i]);
	}

	for(int j = 10; j >= 0; j--){
		val = Func(array[j]);
		if(val > 400){
			printf("%f TOO LARGE\n", val);
		}
		else{
			printf("%f\n", val);
		}
	}


}


