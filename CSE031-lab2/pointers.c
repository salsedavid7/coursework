#include <stdio.h>
int main(void) {

    int x = 0;
    int y = 0;
    int *px, *py;
    int arr[10];

    for(int i = 0; i < 10; i++) {
        arr[i] = 0;
  }
    printf("%d, %d, %d \n", x, y, arr[0]);
    printf("Address of x: %p\n", &x);
    printf("Address of y: %p\n", &y);
    px = &x;
    py = &y;

    printf("px = %p, Address of px = %p\n" ,px, &px);
    printf("py = %p, Address of py = %p\n" ,py, &py);

  for(int i = 0; i < 10; i++) {
      printf("content of %d element is %d arr + i is %p \n", i, *(arr + i), arr +i);
  }
    printf("arr %p, address of arr[0] %p", &arr, &arr[0]);
    return 0;

    


}
