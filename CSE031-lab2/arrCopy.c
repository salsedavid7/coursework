#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArr(int *a, int size, char *name){
	int i = 0;
    printf("\n");
    printf("%s", name);
    printf(" array contents: ");
    for(i = 0; i < size; i++) {
        printf("%d", *(a + i));
        printf(" ");
    }
}

int* arrCopy(int *a, int size){
	int* copyArr = (int *)malloc(size * sizeof(int));
    int i;
    for(i = 0; i < size; i++){
        *(copyArr + i) = *(a + i);
    }
    return copyArr;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        int num = 0;
        printf("Enter array element #%d: ", i);
        scanf("%d", &num);
        *(arr + i) = num;
        
    }

    //Dynamically create an int array of n items
    //Your code here

    //Ask user to input content of array
	//Your code here
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n, "Original");

	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n, "Copied");

    printf("\n");

    return 0;
}