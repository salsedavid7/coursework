#include <stdio.h>

int read_values(double* sum) {
    int values=0,input=0;
    *sum = 0;
    printf("Enter input values (enter 0 to finish): ");
    scanf("%d",&input);
    while(input != 0) {
        values++;
        *sum += input;
        scanf("%d",&input);
    }
    return values;
}

int main() {
    double sum=0;
    int values;
    values = read_values(&sum);
    printf("Average: %g ", sum / values);
    return 0;
}
