#include <stdio.h>


// 1,2,3,4 -> 10
// 0 -> 0
// 1 -> 1
// 0,1 -> 1
// 5,5,5,-10,-10,-100,5,5 -> 15
// 100, -1000, 50 -> 100
// -1000, 5, 5, 5, -1000, 5 -> 15
// -1000, 5, 5, 5, -10, 5, 5, 5 -> 20
// -1000, 5, 5, 5, -1000, 5, 5, 5 -> 15
// 5, 5, 5, -10, 5, 5, 5, -10, 5, 5, 5 -> 25
// 5, 5, 5, -10, 5, 5, 5, -10, 5, 5, 5, -1000, 117 -> 117
// 131, -1000, 5, 5, 5, -10, 5, 5, 5, -10, 5, 5, 5, -1000, 117 -> 131
// 2000, -1000, 5, 5, 5 -> 2000
// 2000, -1000, 5, 5, 5, -10000, 3000 -> 3000
// 2000, -1000, 5, 5, 5, -10000, 3000, -500, 1000 -> 3500
// 2000, -1000, 5, 5, 5, -1000, -100, -100, -10000, 3000, -500, 1000 -> 3500
// 2000, -1000, 5, 5, 5, -1000, -100, -100, -1000, 5, 5, 5, -10000, 3000, -500, 1000 -> 3500
// 2000, -1000, 5, 5, 5, -1000, -10000, -10000, -10000, 5, 5, 5, -10000, 3000, -500, 1000, -1000000, 10000, 10000, 10000, 10000-> 40000

int get_sum(const int* array, int length) {
    if (length == 1)
        return array[0] > 0 ? array[0] : 0;

    int left = 0;
    int right = -1;
    int sum = 0;
    int best_sum = sum;

    while (left < length - 1 && right < length - 1) {
        if (sum + array[right + 1] >= 0) {                          //  epxanding window
            sum += array[right + 1];                        
            ++right;                        
        } else if (left < right) {                                  //  shrinking window
            sum -= array[left];                     
            ++left;                     
        } else {                                                    //  window is shrinked, moving both pointers
            sum += array[right + 1];                        
            sum -= array[left];                     
                        
            ++right;                        
            ++left;                     
        }                       
                        
        if (sum > best_sum)                                         //  updating maximum
            best_sum = sum;
    }
   
    return best_sum;
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

void get_sum_test(int (*algorithm)(const int*, int)) {
    int test_number = 1;
    int successful_test_number = 0;
   
    {
        const int input[] = {1,2,3,4};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 10;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {0};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 0;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {1};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 1;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {-10};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 0;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {-5,-5,-5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 0;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {0,1};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 1;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {5,5,5,-10,-10,-100,5,5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 15;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {100, -1000, 50 };
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 100;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {-1000, 5, 5, 5, -1000, 5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 15;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {-1000, 5, 5, 5, -10, 5, 5, 5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 20;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {-1000, 5, 5, 5, -1000, 5, 5, 5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 15;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = { 5, 5, 5, -10, 5, 5, 5, -10, 5, 5, 5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 25;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {5, 5, 5, -10, 5, 5, 5, -10, 5, 5, 5, -1000, 117};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 117;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {131, -1000, 5, 5, 5, -10, 5, 5, 5, -10, 5, 5, 5, -1000, 117 };
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 131;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {2000, -1000, 5, 5, 5};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 2000;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {2000, -1000, 5, 5, 5, -10000, 3000};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 3000;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {2000, -1000, 5, 5, 5, -10000, 3000, -500, 1000};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 3500;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;
    
    {
        const int input[] = {2000, -1000, 5, 5, 5, -1000, -100, -100, -10000, 3000, -500, 1000};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 3500;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {2000, -1000, 5, 5, 5, -1000, -100, -100, -1000, 5, 5, 5, -10000, 3000, -500, 1000};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 3500;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {2000, -1000, 5, 5, 5, -1000, -10000, -10000, -10000, 5, 5, 5, -10000, 3000, -500, 1000};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 3500;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }
    ++test_number;

    {
        const int input[] = {2000, -1000, 5, 5, 5, -1000, -10000, -10000, -10000, 5, 5, 5, -10000, 3000, -500, 1000, -1000000, 10000, 10000, 10000, 10000};
        const int length = sizeof(input) / sizeof(input[0]);
        const int expected = 40000;
        const int actual = algorithm(input, length);

        test_case(test_number, &successful_test_number, actual, expected, input, length);
    }

    printf("SUMMARY:\t%d / %d, %.2f%%\n", successful_test_number, test_number, 100.0f * (float)successful_test_number / (float)test_number);
}

int main() {
    get_sum_test(get_sum);
    return 0;
}