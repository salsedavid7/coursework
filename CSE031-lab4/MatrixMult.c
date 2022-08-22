
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

int** matMult(int **a, int **b, int size){
	//allocate memory for a 2d array
	int **multiply = (int**)malloc(size *sizeof(int*)); 
	int i,c,d,e,sum=0;

	for (i=0; i<size; i++) 
	//multiply[i] has size elements or multiply[0][size], multiply[1][size]...
	*(multiply + i) = (int *)malloc(size * sizeof(int));

	for (c = 0; c < size; c++) { //increments rows top to bottom for matrix c
		for (d = 0; d < size; d++) { //increments columns left to right for matrix c
			for (e = 0; e < size; e++) { //iterates thru all elements in a and b. 
				sum = sum + *(*(a + c) + e) * *(*(b + e) + d); //a[c][e] * b[e][d] ; //responsible for solving for one element in matrix c
			}
			*(*(multiply + c) + d) = sum; //sum = multiply[c][d] = sum
			sum = 0; //resets equation
		}
	}
return multiply;
}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	int x, y;
	for(x = 0; x < n; x++) {
		for(y = 0; y < n; y++) {
			printf("%d\t", *(*(arr + x) + y)); //print [0][0], print[0][1]...
		}
		printf("\n");
	}
	printf("\n");

}

int main() {
	int n=3;
	int **matA, **matB, **matC;
	int k = 5;

	// (1) Define 2 n x n arrays (matrices). 
	matA = (int**)malloc(n *sizeof(int*));
	for(int i = 0; i < n; i++) {
		*(matA + i) = (int*)malloc(n*sizeof(int*)); //mat[0] = size
		for(int j = 0; j < n; j++) {
			*(*(matA + i) + j) = (j + 1) * k; //matA[0][0], matA[0][1], matA[0][2], mat[1][0]
		}
	}

	matB = (int**)malloc(n *sizeof(int*));
	for(int i = 0; i < n; i++) {
		*(matB + i) = (int*)malloc(n*sizeof(int*)); //matB[i][size]
		for(int j = 0; j < n; j++) { //matb[i][j] = 0
			*(*(matB + i) + j) = 1 ;  //matb[j][i] = 1
		}
	}

	// (3) Call printArray to print out the 2 arrays here.
	printf("Matrix A is: \n");
	printArray(matA, n);

	printf("\nMatrix B is: \n");
	printArray(matB, n);
	
	//(5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	printf("Matrix Multiplation = \n");
	//(6) Call printArray to print out resulting array here.
	printArray(matC,n);


    return 0;
}