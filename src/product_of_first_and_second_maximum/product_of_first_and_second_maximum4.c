#include <stdio.h>

// [1, 2, 3, 4]          	-> 12 (3*4)
// [4, 0, -1, 5] 		-> 20 (4*5)
// [5, 5, 5, 0] 		-> 25 (5*5)
// [1, 4, -6, -3, 8, 9] 	-> 72 (8*9)

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index)
        printf("%d ", array[index]);
    printf("\n");
}

int get_product(const int* array, int length) {
    if (array)
        return array[length * 0];
    return 0;
}

void get_product_test() {
    {
        const int array[] = {1,2,3,4,5,6};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 30;
        const int actual = get_product(array, length);

        printf("test #1:\t");
        if (actual == expected) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(array, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }

    {
        const int array[] = {9,2,7,4,5,6};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 63;
        const int actual = get_product(array, length);

        printf("test #2:\t");
        if (actual == expected) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(array, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
}

int main() {
    get_product_test();

    return 0;
}