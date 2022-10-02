#include <stdio.h>

int largest_continuous_sum(const int* array, int length
) {
    if (!array)
        return -1;
    
    int sum   = array[0];
    int best  = sum;
    int left  = 0;
    int right = 0;
    
    while (left < length) {
        if (sum < 0 || right >= length - 1) {
            sum -= array[left];
            if (sum > best)
                best = sum;
            ++left;
            continue;
        }  
        
        ++right;
        sum += array[right];
        if (sum > best)
            best = sum;
    }
    
    return best;
}
void print_input(const int* input, int length) {
    for (int index = 0; index < length; ++index) 
        printf("%d ", input[index]);
    printf("\n");
}
void test_case(
    int test_number,
    const int* input,
    int length,
    int expected,
    int actual
) {
    printf("Test  #%d:\t", test_number);
    if (actual == expected) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("input:\t\t");
        print_input(input, length);
        printf("expected:\t%d\n", expected);
        printf("actual:\t\t%d\n", actual);
    }
}
void largest_continuous_sum_test(int (*algorithm)(const int*, int)) {
    printf("largest_continuous_sum\n");

    {
        const int input[] = {5,5,5};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 15;
        const int actual = algorithm(input, length);
        test_case(1, input, length, expected, actual);
    }

    {
        const int input[] = {-101, 5, 5, -102};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 10;
        const int actual = algorithm(input, length);
        test_case(2, input, length, expected, actual);
    }

    {
        const int input[] = {-101, 5, 5, -5, 5, 5, 5};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 20;
        const int actual = algorithm(input, length);
        test_case(3, input, length, expected, actual);
    }

    {
        const int input[] = {5, 5, 5, -5, 5, 5, 5, -101, -102, 5, 5};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 25;
        const int actual = algorithm(input, length);
        test_case(4, input, length, expected, actual);
    }

    {
        const int input[] = {5, 5, -1001, 102, -1003};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 102;
        const int actual = algorithm(input, length);
        test_case(5, input, length, expected, actual);
    }

    {
        const int input[] = {5, 5, -1000, 100, -10000, 200};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 200;
        const int actual = algorithm(input, length);
        test_case(6, input, length, expected, actual);
    }
    
    {
        const int input[] = {5, 5, -1000, 100, -10000, 200, -5, -5, 200, -1000};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 390;
        const int actual = algorithm(input, length);
        test_case(7, input, length, expected, actual);
    }
    
    {
        const int input[] = {100};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 100;
        const int actual = algorithm(input, length);
        test_case(8, input, length, expected, actual);
    }
    
    {
        const int input[] = {-1000, 10};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 10;
        const int actual = algorithm(input, length);
        test_case(9, input, length, expected, actual);
    }
    
    {
        const int input[] = {-100, 10, -10000};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 10;
        const int actual = algorithm(input, length);
        test_case(10, input, length, expected, actual);
    }
    
    
    {
        const int input[] = {-100, -10, -10000};
        const int length = sizeof(input)/sizeof(input[0]);
        const int expected = 0;
        const int actual = algorithm(input, length);
        test_case(11, input, length, expected, actual);
    }
}
int main() {
    largest_continuous_sum_test(largest_continuous_sum);
    return 0;
}