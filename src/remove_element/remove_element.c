#include <stdio.h>

void print_array(const int* array, int length) {
    for (int index = 0; index < length; ++index)
        printf("%d ", array[index]);
    printf("\n");
}
int remove_element(int *array, int length, int element_to_remove) {
    int index_in_new_array = 0;
    for (int index = 0; index < length; ++index) {
        if (array[index] == element_to_remove) {
            continue;
        }
        array[index_in_new_array] = array[index];
        ++index_in_new_array;
    }

    return index_in_new_array; // this is new the length after removing
}


int main() {
    int input1[] = {1,1,1,2,3,4,2,1,1,1,5,3};
    const int length1 = sizeof(input1) / sizeof(input1[0]);
    const int new_length1 = remove_element(input1, length1, 1);
    print_array(input1, new_length1);
    
    int input2[] = {1,1,1,2,3,4,2,1,1,1,5,3};
    const int length2 = sizeof(input2) / sizeof(input2[0]);
    const int new_length2 = remove_element(input2, length2, 2);
    print_array(input2, new_length2);
    
    int input3[] = {1,1,1,2,3,4,2,1,1,1,5,3};
    const int length3 = sizeof(input3) / sizeof(input3[0]);
    const int new_length3 = remove_element(input3, length3, 1487);
    print_array(input3, new_length3);
    
    
    return 0;
}