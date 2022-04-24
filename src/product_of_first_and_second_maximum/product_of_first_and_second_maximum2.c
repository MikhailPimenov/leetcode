#include <stdio.h>


int get_product(const int *array, int length) {
    if (length < 2)
        return -1;

    int first  = -1;
    int second = -1;
    
    if (array[0] > array[1]) {
        first  = array[0];
        second = array[1];
    } else {
        first  = array[1];
        second = array[0];
    }
    
    for (int index = 2; index < length; ++index) {
        if (array[index] > second) {
            if (array[index] <= first) {
                second = array[index];
                continue;
            }
            second = first;
            first  = array[index];
        }
    }

    return first * second;
}

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index)
        printf("%d ", array[index]);
    printf("\n");
}
void test_case(
    int test_number,
    const int* input,
    int length, 
    int expected,
    int actual) {
    
    printf("Test  #%d\t", test_number);
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

void get_product_test(int (*algorithm)(const int*, int)) {
     printf("Testing product of first and second maximum:\n");

    {
        const int input[] = {1,2,3,4,5};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 20;
        const int actual   = algorithm(input, length);
        test_case(1, input, length, expected, actual);
    }
    
    {
        const int input[] = {1,2,3,9,4,5,5,8,4};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 72;
        const int actual   = algorithm(input, length);
        test_case(2, input, length, expected, actual);
    }
    
    {
        const int input[] = {4,4,4,4,4};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 16;
        const int actual   = algorithm(input, length);
        test_case(3, input, length, expected, actual);
    }
    
    {
        const int input[] = {-1,-10,-5,4,0};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 0;
        const int actual   = algorithm(input, length);
        test_case(4, input, length, expected, actual);
    }
    
    {
        const int input[] = {3,2};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 6;
        const int actual   = algorithm(input, length);
        test_case(5, input, length, expected, actual);
    }
    
    {
        const int input[] = {3};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = -1;
        const int actual   = algorithm(input, length);
        test_case(6, input, length, expected, actual);
    }
    
    {
        const int input[] = {3,2,0,1,0,1,1,0};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 6;
        const int actual   = algorithm(input, length);
        test_case(7, input, length, expected, actual);
    }
    
    {
        const int input[] = {5,5,6,3,5,3,2,1,7,4,3,8,4,8,5};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 64;
        const int actual   = algorithm(input, length);
        test_case(8, input, length, expected, actual);
    }
    
    {
        const int input[] = {10,5,6,3,5,3,2,1,7,4,3,8,4,8,9};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 90;
        const int actual   = algorithm(input, length);
        test_case(9, input, length, expected, actual);
    }
    
    {
        const int input[] = {10,5,6,3,5,3,2,1,7,4,3,8,4,8,-9};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 80;
        const int actual   = algorithm(input, length);
        test_case(10, input, length, expected, actual);
    }
    
    {
        const int input[] = {0,0,0,4,0,0,3,0,0,1,0};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 12;
        const int actual   = algorithm(input, length);
        test_case(11, input, length, expected, actual);
    }
    
    {
        const int input[] = {7,6,0,4,0,0,3,0,0,1,0};
        const int length = sizeof(input) / sizeof(input[0]);
        
        const int expected = 42;
        const int actual   = algorithm(input, length);
        test_case(12, input, length, expected, actual);
    }
    
}

int main() {
    get_product_test(get_product);
    
    return 0;
}
