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

void get_product_test(int (*algorithm)(const int*, int)) {
    int test_number = 0;
    int successful_test_number = 0;
    {
        const int array[] = {1,2,3,4,5,6};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 30;

        const int actual = algorithm(array, length);

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
        const int array[] = {1,2,3,4,5,6,7,8};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 56;

        const int actual = algorithm(array, length);

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

    printf("SUMMARY:\t%d / %d, %.2f%%\n", successful_test_number, test_number, 100.0f * (float)successful_test_number / (float)test_number);
}

int main() {
    get_product_test(get_product);

    return 0;
}