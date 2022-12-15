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
    int test_number = 1;
    int successful_test_number = 0;
    {
        const int array[] = {1,2,3,4,5,6};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 30;
        const int actual = get_product(array, length);

        printf("test #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
            ++successful_test_number;
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(array, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
    ++test_number;

    {
        const int array[] = {9,2,7,4,5,6};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 63;
        const int actual = get_product(array, length);

        printf("test #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
            ++successful_test_number;
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(array, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }

    printf("\nSUMMARY:\n");
    printf("tests:\t\t%d\n", test_number);
    printf("passed:\t\t%d\n", successful_test_number);
    printf("failed:\t\t%d\n", test_number - successful_test_number);
    printf("percentage:\t%.2f\n", (float)successful_test_number / (float)test_number);
}

int main() {
    get_product_test();

    return 0;
}