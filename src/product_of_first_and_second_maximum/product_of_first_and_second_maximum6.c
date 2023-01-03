#include <stdio.h>
#include <stdlib.h>

int get_product(const int* array, int length) {
    if (length < 2)
        return -1;

    int first = array[0] > array[1] ? array[0] : array[1];
    int second = array[0] < array[1] ? array[0] : array[1];

    for (int index = 2; index < length; ++index) {
        const int current = array[index];
        if (current > first) {
            second = first;
            first = current;
        } else if (current > second) {
            second = current;
        }
    }

    return first * second;
}

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index)
        printf("%d ", array[index]);
    printf("\n");
}

void test_case(int test_number, int* successful_test_number, int actual, int expected, const int* input, int input_length, int is_verbose) {
    printf("test #%d:\t", test_number);
    if (actual == expected) {
        printf("ok\n");
        ++(*successful_test_number);
    } else {
        printf("FAILED\n");

        if (is_verbose) {
            printf("input:\t\t");
            print_array(input, input_length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
}

void get_product_test(int (*algorithm)(const int*, int), int is_verbose) {
    int test_number = 0;
    int successful_test_number = 0;
    {
        const int array[] = {1,2,3,4,5,6};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 30;

        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {1,2,3,4,5,6,7,8};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 56;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {0,0,0,0};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 0;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {0,0,0,0,8,1};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 8;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {9,0,0,0,0,8,1};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 72;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;


    {
        const int array[] = {9,11,0,0,0,0,8,1};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 99;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {9,0,0,0,0,8,111,10};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 1110;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {7,6,8,0,9,0,8,1};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 72;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {1};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = -1;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {5};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = -1;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {5,5};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 25;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        const int array[] = {0,0};
        const int length = sizeof(array) / sizeof(array[0]);
        const int expected = 0;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
    }
    ++test_number;

    {
        int* array = malloc(1 * sizeof(int));
        array[0] = 5;
        const int length = 1;
        const int expected = -1;

        const int actual = algorithm(array, length);
        
        test_case(test_number, &successful_test_number, actual, expected, array, length, is_verbose);
        free(array);
    }
    ++test_number;


    printf("SUMMARY:\t%d / %d, %.2f%%\n", successful_test_number, test_number, 100.0f * (float)successful_test_number / (float)test_number);
}

enum MyBoolean {
    False = 0,
    True = 1
};

int main() {
    get_product_test(get_product, False);

    return 0;
}