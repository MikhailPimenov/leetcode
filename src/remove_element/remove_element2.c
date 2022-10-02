#include "stdio.h"


// 1 2 1 2 1 4 5 1 0 1    1
// 2 2 4 5 0 .........
int remove_element2(int* array, int length, int element) {
    int index_in_new_array = 0;

    for (int index = 0; index < length; ++index) {
        if (array[index] != element) {
            array[index_in_new_array] = array[index];
            ++index_in_new_array;
        }
    }

    return index_in_new_array;
}

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index)
        printf("%d ", array[index]);

    printf("\n");
}

int main() {
    {
        int input[] = { 1, 2, 1, 2, 1, 4, 5, 1, 0, 1 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int new_length = remove_element2(input, length, 1);
        print_array(input, new_length);
    }

    {
        int input[] = { 1, 2, 1, 2, 1, 4, 5, 1, 0, 1, 0, 9, 4};
        const int length = sizeof(input) / sizeof(input[0]);

        const int new_length = remove_element2(input, length, 0);
        print_array(input, new_length);
    }

    {
        int input[] = { 4, 3, 4, 0, 1, 2, 1, 2, 1, 4, 5, 1, 0, 1 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int new_length = remove_element2(input, length, 4);
        print_array(input, new_length);
    }

    {
        int input[] = { 4, 4, 4, 4, 4 };
        const int length = sizeof(input) / sizeof(input[0]);

        const int new_length = remove_element2(input, length, 4);
        print_array(input, new_length);
    }
}