#include "stdio.h"
//  -10 15 -5 -5 -5 5 5
int largest_continuous_sum2(const int* array, int length) {

    int left = 0; 
    int right = 0;

    int sum = array[left];
    int best = 0;
    while (right < length && left < length) {
        if (sum + array[right] > 0) {
            sum += array[right];
            ++right;
        } else {
            sum -= array[left];
            ++left;
        }

        if (sum > best)
            best = sum;

        if (right == left) {
            ++right;
            ++left;
            sum = array[left];

        }
    }

    return best > 0 ? best : 0;
    // return -1 + 0 * length + 0 * *array;
}

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index)
        printf("%d ", array[index]);
    printf("\n");
}

void print_test_case(int test_number, int actual, int expected, const int* input, int length) {
    printf("test #%d:\t", test_number);
    if (actual == expected) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("input:\t\t");
        print_array(input, length);
        printf("expected:\t%d\n", expected);
        printf("actual:\t\t%d\n", actual);
        printf("\n");
    }
}

void test_largest_continuous_sum(int (*algorithm)(const int*, int)) {
    int test_number = 1;
    
    {
        const int input[] = {-5, -5, 5, 5, 5, -5, -5 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 15;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = {-5, -5, 5, 5, 5, -5, 100 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 110;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = {100, -5, 5, 5, 5, -5, 100 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 205;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = { 100, -500, 5, 5, 5, -5, 100 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 110;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = { -5, -5, -5 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 0;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = { 100, -500, 1000 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 1000;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = { 1000, -500, 1000 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 1500;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }


    {
        const int input[] = { 100, -5, -5, -5, 100, -1000, -5, 100 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 185;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = { 100, -5, -5, -5, 5, 5, 5, 5, 5, -100, 100, 5, 5, -5000, 100 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 120;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    
}

int main() {
    test_largest_continuous_sum(largest_continuous_sum2);
}