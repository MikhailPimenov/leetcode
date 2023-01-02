#include <stdio.h>

// 1,2,3  1 -> 2,3

// 1,2,3,4,1,1,2,3,4,5  1 -> 2,3,4,2,3,4,5

// 1,2,3,4,1,1,2,3,4,5  2 -> 1,3,4,1,1,3,4,5

int are_equal(const int* array1, const int* array2, int length) {
    for (int index = 0; index < length; ++index) 
        if (array1[index] != array2[index])
            return 0;                                               // not equal
    
    return 1;                                                       // equal
}

int remove_elements(int* array, int length, int element) {
    int index_in_new_array = 0;

    for (int index = 0; index < length; ++index) {
        if (array[index] != element) {
            array[index_in_new_array] = array[index];
            ++index_in_new_array;
        }
    }
    return index_in_new_array;  // length of array with removed elements
}

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index) 
        printf("%d ", array[index]);

    printf("\n");
}

void test_case(int test_number, 
               int* successful_test_number, 
               const int* expected, 
               int expected_length, 
               const int* actual, 
               int actual_length, 
               const int* input, 
               int length) {
    printf("test #%d:\t\t", test_number);
    if (actual_length == expected_length && are_equal(actual, expected, expected_length)) {
        printf("ok\n");
        ++(*successful_test_number);
    } else {
        printf("FAILED\n");
        printf("input:\t\t\t");
        print_array(input, length);
        printf("expected:\t\t");
        print_array(expected, expected_length);
        printf("expected_length:\t%d\n", expected_length);
        printf("actual:\t\t\t");
        print_array(actual, actual_length <= length ? actual_length : length);
        printf("actual_length:\t\t%d\n", actual_length);
    }
}

void remove_elements_test(int (*algorithm)(int*, int, int)) {
    int test_number = 0;
    int successful_test_number = 0;
    {
        int input[] = {1,2,3,4};
        const int input_copy[] = {1,2,3,4};
        const int length = sizeof(input) / sizeof(input[0]);
        const int element_to_remove = 1;

        const int expected[] = {2,3,4};
        const int expected_length = sizeof(expected) / sizeof(expected[0]);

        const int actual_length = algorithm(input, length, element_to_remove);

        test_case(test_number, &successful_test_number, expected, expected_length, input, actual_length, input_copy, length);
    }
    ++test_number;

    {
        int input[] = {1,1,1,1,1,2,1,1,1,1,3,1,1,1,4,1,1,1};
        const int input_copy[] = {1,1,1,1,1,2,1,1,1,1,3,1,1,1,4,1,1,1};
        const int length = sizeof(input) / sizeof(input[0]);
        const int element_to_remove = 1;

        const int expected[] = {2,3,4};
        const int expected_length = sizeof(expected) / sizeof(expected[0]);

        const int actual_length = algorithm(input, length, element_to_remove);

        test_case(test_number, &successful_test_number, expected, expected_length, input, actual_length, input_copy, length);
    }
    ++test_number;

    {
        int input[] = {1,2,3,4};
        const int input_copy[] = {1,2,3,4};
        const int length = sizeof(input) / sizeof(input[0]);
        const int element_to_remove = 2;

        const int expected[] = {1,3,4};
        const int expected_length = sizeof(expected) / sizeof(expected[0]);

        const int actual_length = algorithm(input, length, element_to_remove);

        test_case(test_number, &successful_test_number, expected, expected_length, input, actual_length, input_copy, length);
    }
    ++test_number;

    {
        int input[] = {1,2,3,4,1,1,2,2,3,4,1,2,2,2,1,2,1,3,4};
        const int input_copy[] = {1,2,3,4,1,1,2,2,3,4,1,2,2,2,1,2,1,3,4};
        const int length = sizeof(input) / sizeof(input[0]);
        const int element_to_remove = 2;

        const int expected[] = {1,3,4,1,1,3,4,1,1,1,3,4};
        const int expected_length = sizeof(expected) / sizeof(expected[0]);

        const int actual_length = algorithm(input, length, element_to_remove);

        test_case(test_number, &successful_test_number, expected, expected_length, input, actual_length, input_copy, length);
    }
    ++test_number;


    printf("SUMMARY:\t\t%d / %d, %.2f%%\n", successful_test_number, test_number, 100.0f * (float)successful_test_number / (float)test_number);
}

int main() {
    remove_elements_test(remove_elements);
    return 0;
}