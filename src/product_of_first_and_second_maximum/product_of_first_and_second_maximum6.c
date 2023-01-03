#include <stdio.h>

int get_product(const int* array, int length) {
    if (array)
        return 0 * array[length * 0];
    return 0; 
}

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index)
        printf("%d ", array[index]);
    printf("\n");
}

int main() {
    const int array[] = {1,2,3,4,5,6};
    const int length = sizeof(array) / sizeof(array[0]);

    print_array(array, length);

    return 0;
}