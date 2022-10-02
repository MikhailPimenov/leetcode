#include <stdio.h>

// #define UNUSED_SHIT(fucking_unused_shit) do { (void)(fucking_unused_shit); } while (0)

static void swap(int* left, int* right) {
    const int temporary = *left;
    *left = *right;
    *right = temporary;
}

void segregate_positive_and_negative_numbers(int *array, int length) {
    int lower = 0;
    int greater = length - 1;

    while (lower < greater) {
        if (array[greater] >= 0) {
            --greater;
        } else {
            swap(array + lower, array + greater);
            ++lower;
        }
    }


    return;
}


// -1 -2 -1 5 5 5
static int is_segregated(const int* array, int length) {
    // int was_negative_before = 0;
    int only_positive_after = 0;
    for (int index = 0; index < length; ++index) {
        if (array[index] < 0) {
            // was_negative_before = 1;
            if (only_positive_after)
                return 0;
        } else {
            only_positive_after = 1;
        }
    }

    return 1;
}

static void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index) {
        printf("%d ", *(array + index));
    }
    printf("\n");
}

static void segregate_positive_and_negative_numbers_test(void (*algorithm)(int*, int)) {
    int test_number = 1;
    
    {
        int input[]      = {1, 2, 3};
        int input_copy[] = {1, 2, 3};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {1, -2, 3};
        int input_copy[] = {1, -2, 3};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {-1, -2, 3};
        int input_copy[] = {-1, -2, 3};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {-1, -2, -3};
        int input_copy[] = {-1, -2, -3};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {-1, -2, -3, 4, 5, 6};
        int input_copy[] = {-1, -2, -3, 4, 5, 6};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {1, -2, -3, 4, 5, 6};
        int input_copy[] = {1, -2, -3, 4, 5, 6};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {-1, 2, -3, 4, -5, 6};
        int input_copy[] = {-1, 2, -3, 4, -5, 6};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {-1, 2, -3, 4, -5, 6, -7, -8, -9};
        int input_copy[] = {-1, 2, -3, 4, -5, 6, -7, -8, -9};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {-1, 2, -3, -4, -5, 6, -7, -8, -9};
        int input_copy[] = {-1, 2, -3, -4, -5, 6, -7, -8, -9};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {-1, -2, -3, -4, -5, 6, -7, -8, -9};
        int input_copy[] = {-1, -2, -3, -4, -5, 6, -7, -8, -9};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {1, 2, -3, -4, -5, 6, -7, 8, -9};
        int input_copy[] = {1, 2, -3, -4, -5, 6, -7, 8, -9};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }


    {
        int input[]      = {1, 2, -3, -4, -5, 6, -7, 8, -9, 0};
        int input_copy[] = {1, 2, -3, -4, -5, 6, -7, 8, -9, 0};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {0, 1, 2, -3, -4, -5, 6, -7, 8, -9, 0};
        int input_copy[] = {0, 1, 2, -3, -4, -5, 6, -7, 8, -9, 0};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }

    {
        int input[]      = {0, 1, 2, -3, 0, -4, -5, 6, -7, 8, -9, 0};
        int input_copy[] = {0, 1, 2, -3, 0, -4, -5, 6, -7, 8, -9, 0};
        const int length = sizeof(input) / sizeof(input[0]);

        algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (is_segregated(input, length)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input_copy, length);
            printf("result:\t\t");
            print_array(input, length);
        }
        ++test_number;
    }
}

static void is_segregated_test(int (*algorithm)(const int*, int)) {
    int test_number = 1;
    {
        const int input[] = {-1, -2, -3};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 1;
        const int actual = algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
    ++test_number;

    {
        const int input[] = {-1, -2, 3};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 1;
        const int actual = algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
    ++test_number;

    {
        const int input[] = {-1, 2, 3};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 1;
        const int actual = algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
    ++test_number;

    {
        const int input[] = {1, 2, 3};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 1;
        const int actual = algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
    ++test_number;


    {
        const int input[] = {1, -2, 3};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 0;
        const int actual = algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
    ++test_number;


    {
        const int input[] = {1, -2, 3, -4};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 0;
        const int actual = algorithm(input, length);

        printf("test  #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\t\t");
            print_array(input, length);
            printf("expected:\t%d\n", expected);
            printf("actual:\t\t%d\n", actual);
        }
    }
    ++test_number;
    
}

int main() {
    segregate_positive_and_negative_numbers_test(segregate_positive_and_negative_numbers);
}