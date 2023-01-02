#include <stdio.h>
    
int get_product(const int* array, int length) {
    if (length < 2)
        return -1;
    
    int first = array[0] > array[1] ? array[0] : array[1];
    int second = array[0] < array[1] ? array[0] : array[1];

    for (int index = 2; index < length; ++index) {
        if (array[index] > first) {
            second = first;
            first = array[index];
        } else if (array[index] > second) {
            second = array[index];
        }
    }

    return first * second;
}

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index) 
        printf("%d ", array[index]);
    printf("\n");
}

void test_case(int test_number, int* successful_test_number, int actual, int expected, const int* input, int length) {
    printf("test #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
            ++(*successful_test_number);
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
}

void get_product_test(int (*algorithm)(const int*, int)) {
    int test_number = 1;
    int successful_test_number = 0;
    
    {
        const int input[] = {1,2,3,4,5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 20;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {1,2,3,4,5,6};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 30;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {1,2,3,4,5,6,7};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 42;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {0,0,0,0};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 0;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {-5,-9,0,0};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 0;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {5,0,0,3};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 15;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {5,0,0,3,0,0,9,0,0,8};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 72;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {9,0,0,3,0,0,9,0,0,8};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 81;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {9,0,0,3,0,0,7,0,0,8};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 72;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {8,0,0,3,0,0,7,0,0,8,9,10};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 90;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {9,7,0,3,0,0,7,0,0,8,5,5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 72;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {0,7,0,3,0,0,9,0,0,8,5,5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 72;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {0,7,0,3,0,0,9,0,0,8,5,5,11,9};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 99;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {0};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = -1;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = -1;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {9};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = -1;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {9,-9};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = -81;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }

    printf("SUMMARY:\t%d / %d, %.2f%%\n", successful_test_number, test_number, 100.0f * (float)successful_test_number / (float)test_number);
}

int main() {
    
    get_product_test(get_product);

    return 0;
}