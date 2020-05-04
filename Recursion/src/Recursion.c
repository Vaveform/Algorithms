#include <stdio.h>
#include <stdlib.h>


// Print recursively decimal positive number to binary
void DecimalNumberToBinary(int decimal_number){
	if(decimal_number < 2){
		printf("%d" , decimal_number);
	}
	else{
		DecimalNumberToBinary(decimal_number / 2);
		printf("%d", decimal_number % 2);
	}
}

//Recursive pow functions: first - simple way (without optimization); second - with optimization
// Simple way (without optimization
int Recursive_simple_way(int base, int degree){
	if(degree == 1){
		return base;
	}
	else if(degree == 0){
		return 1;
	}
	else if(degree < 0){
		return -1;
	}
	else{
		return base * Recursive_simple_way(base, degree - 1);
	}
}

// Way with optimization
int Recursive_optimization(int base, int degree){
	if(degree == 1){
		return base;
	}
	else if(degree == 0){
		return 1;
	}
	else if(degree % 2 == 0){
		return Recursive_optimization(base, degree / 2) *
				Recursive_optimization(base, degree / 2);
	}
	else if(degree < 0){
		return -1;
	}
	else{
		return base * Recursive_optimization(base, degree - 1);
	}
}

int routes(int y, int x, int** obstacles){
	// if we found on current position obstacle return 0
	if(obstacles[y][x] == 1){
		return 0;
	}
	else{
		// In task said that our king start from top left position (0,0)
		if(x == 0 && y == 0){
			return 0;
		}
		// For every position top side and left side of table we have
		else if(x == 0 && y != 1){
				return 1 * routes(y - 1, x, obstacles);
		}
		else if(x == 0 && y == 1){
				return obstacles[y][x] == 1 ? 0 : 1;
		}
		else if(y == 0 && x != 1){
				return 1 * routes(y, x - 1, obstacles);
		}
		else if(y == 0 && x == 1){
				return obstacles[y][x] == 1 ? 0 : 1;
		}
		else{
			// Calculate recursively number of ways for current position
			return routes(y - 1, x, obstacles) + routes(y, x - 1, obstacles);
		}
	}
}

int main(void) {
	// First part of task
	DecimalNumberToBinary(126);
	// Second part of task
	printf("\n%d", Recursive_simple_way(2, 10));
	printf("\n%d\n", Recursive_optimization(2, 10));

	//Third part of task
	const int x_size = 6;
	const int y_size = 6;
	// Dynamic allocation for array with obstacles
	int** obstacles = (int **)malloc(y_size * sizeof(int*));
	printf("Obstacles mask:\n");
	for(int i = 0; i < y_size; i++){
		obstacles[i] = (int *)malloc(x_size * sizeof(int));
		for(int j = 0; j < x_size; j++){
			if(i == 0 && j == 2){
				obstacles[i][j] = 1;
			}
			else if(i == 2 && j == 1){
				obstacles[i][j] = 1;
			}
			else if(i == 2 && j == 2){
				obstacles[i][j] = 1;
			}
			else{
				obstacles[i][j] = 0;
			}
			printf("%5d", obstacles[i][j]);
		}
		printf("\n");
	}
	// Number of routes for every position
	printf("Number of routes\n");
	for(int i = 0; i < y_size; i++){
		for(int j = 0; j < x_size; j++){
			printf("%5d", routes(i, j, obstacles));
		}
		printf("\n");
	}
	// Deleting array with obstacles
	for(int i = 0; i < y_size; i++){
		free(obstacles[i]);
	}
	free(obstacles);
	return 0;
}
