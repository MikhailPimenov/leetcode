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
    if (length < 2)
        return -1;

    int first = array[0] > array[1] ? array[0] : array[1];   // taking the largest of 0 and 1 elements
    int second = array[0] < array[1] ? array[0] : array[1];  // taking the smallest of 0 and 1 elements

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

void test_case(int test_number, int* successful_test_number, int actual, int expected, const int* input, int length_input) {
    printf("test #%d:\t", test_number);
    if (actual == expected) {
        printf("ok\n");
        ++(*successful_test_number);
    } else {
        printf("FAILED\n");
        printf("input:\t\t");
        print_array(input, length_input);
        printf("expected:\t%d\n", expected);
        printf("actual:\t\t%d\n", actual);
    }
}

void get_product_test(int (*algorithm)(const int*, int), const char* function_name) {
    printf("testing:\t%s\n", function_name);

    int test_number = 1;
    int successful_test_number = 0;
    {
        const int array[] = {1,2,3,4,5,6};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 30;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }
    ++test_number;

    {
        const int array[] = {9,2,7,4,5,6};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 63;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }




    ++test_number;

    {
        const int array[] = {9,2,7,4,5,6,11};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 99;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }


    ++test_number;

    {
        const int array[] = {0,9,7,4,5,8,6};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 72;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }


    ++test_number;

    {
        const int array[] = {8,9,7,4,5,0,0};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 72;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }


    ++test_number;

    {
        const int array[] = {1,1,5,4,5,0,0,8,7};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 56;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }


    ++test_number;

    {
        const int array[] = {5,4};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = 20;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }


    ++test_number;

    {
        const int array[] = {5};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = -1;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }


    ++test_number;

    {
        const int array[] = {9};
        const int length = sizeof(array) / sizeof(array[0]);

        const int expected = -1;
        const int actual = algorithm(array, length);

        test_case(test_number, &successful_test_number, actual, expected, array, length);
    }

    

    printf("\nSUMMARY:\n");
    printf("passed:\t\t%d\n", successful_test_number);
    printf("failed:\t\t%d\n", test_number - successful_test_number);
    printf("tests:\t\t%d / %d\n", successful_test_number, test_number);
    printf("percentage:\t%.2f\n", (float)successful_test_number / (float)test_number);
}

int main() {
    get_product_test(get_product, "get_product");

    return 0;
}