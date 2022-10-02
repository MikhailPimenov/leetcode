#include "stdio.h"
//  -10 20 -5 -5 -5 10 10 -5
//  -10 200 -50 -50 -50 10 10 -5
int largest_continuous_sum2(const int* array, int length) {
    int left = 0; 
    int right = 0;
    int sum = array[left];
    int best = 0;
    while (1) {
        if (sum < 0) {  //  shrinking

            if (left < right) {  //  can shrink
                
                ++left;
                sum -= array[left];

                if (sum > best)
                    best = sum;

            } else if (right + 1 < length) {  // cannot shrink => stepping over 

                ++left;
                ++right;
                sum = array[left];

                if (sum > best)
                    best = sum;

            } else {
                break;
            }
        
        } else {  //  expanding
            if (right + 1 < length) {
                ++right;
                sum += array[right];

                if (sum > best)
                    best = sum;
            } else {
                ++left;
                sum -= array[left];

                if (sum > best)
                    best = sum;
            }
        }       
        
        if (left == length - 1 && right == length - 1)
            break;
    }

    return best > 0 ? best : 0;
}


int _go_on(int left, int right, int length) {
    return left + 1 < length && right + 1 < length;
}

int _should_expand(int sum, int right, int length) {
    if (sum < 0) 
        return 0;

    if (right + 1 >= length)
        return 0;

    return 1;
}

int _should_shrink(int sum, int left, int right, int length) {
    if (right + 1 >= length && left + 1 < length)
        return 1;

    if (sum < 0 && left < right)
        return 1;

    return 0; 
}

void _expand(const int* array, int* sum, int* right) {
    ++(*right);
    (*sum) += array[*right];
}

void _shrink(const int* array, int* sum, int* left) {
    (*sum) -= array[*left];
    ++(*left);
}

void _step_over(const int* array, int* sum, int* left, int* right) {
    ++(*right);
    ++(*left);
    (*sum) = array[*left];
}

void _update(int sum, int* best) {
    if (sum > *best)
        *best = sum;
}

int largest_continuous_sum3(const int* array, int length) {
    int left = 0; 
    int right = 0;
    int sum = array[left];
    int best = sum;
 

    while (_go_on(left, right, length)) {
        if (_should_expand(sum, right, length)) 
            _expand(array, &sum, &right);
        else if (_should_shrink(sum, left, right, length))
            _shrink(array, &sum, &left);
        else   
            _step_over(array, &sum, &left, &right);

        _update(sum, &best);  
    }

    return best > 0 ? best : 0;
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

    {
        const int input[] = { -10, 20, -5, -5, -5, 10, 10, -5 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 25;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = { -10, 200, -50, -50, -50, 10, 10, -5 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 200;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    {
        const int input[] = { 10, -100, 1000, -10000, 100000, -1000000 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int expected = 100000;
        const int actual = algorithm(input, length);

        print_test_case(test_number, actual, expected, input, length);
        ++test_number;
    }

    
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
    test_largest_continuous_sum(largest_continuous_sum3);
    largest_continuous_sum_test(largest_continuous_sum3);
}