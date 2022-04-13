#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& elements) {
    for (auto element: elements)
        out << element << ' ';

    return out;
}

void swap(int &a, int &b) {
    const int temporary = a;
    a = b;
    b = temporary;
}

void move_zeros_to_the_end(std::vector<int> &numbers) {
    const int size = numbers.size();
    for (int index1 = 0; index1 < size - 1; ++index1) {
        for (int index2 = 0; index2 < size - 1 - index1; ++index2) {
            if (numbers[index2] == 0) {
                swap(numbers[index2], numbers[index2 + 1]);
            }
        }
    }
    return;
}

void test_case(
    int test_number, 
    const std::vector<int> &input, 
    const std::vector<int> &expected, 
    const std::vector<int> &actual) {
        
    std::cout << "Test  #" << test_number << ":\t";
    if (expected == actual) {
        std::cout << "ok\n";
    } else {
        std::cout << "FAILED\n";
        std::cout << "input   :\t" << input    << '\n';
        std::cout << "expected:\t" << expected << '\n';
        std::cout << "actual  :\t" << actual   << '\n';
    }
    
}
void move_zeros_to_the_end_test(void (*algorithm)(std::vector<int>&)) {
    const std::vector<int> input1 {1,1,1,1};
    const std::vector<int> expected1 {1,1,1,1};
    std::vector<int> actual1 {1,1,1,1};
    algorithm(actual1);
    test_case(1, input1, expected1, actual1);
    
    const std::vector<int> input2 {0,1,1,1};
    const std::vector<int> expected2 {1,1,1,0};
    std::vector<int> actual2 {0,1,1,1};
    algorithm(actual2);
    test_case(2, input2, expected2, actual2);
    
    const std::vector<int> input3 {0,0,1,1};
    const std::vector<int> expected3 {1,1,0,0};
    std::vector<int> actual3 {0,0,1,1};
    algorithm(actual3);
    test_case(3, input3, expected3, actual3);
    
    const std::vector<int> input4 {0,0,0,0,0};
    const std::vector<int> expected4 {0,0,0,0,0};
    std::vector<int> actual4 {0,0,0,0,0};
    algorithm(actual4);
    test_case(4, input4, expected4, actual4);
    
    const std::vector<int> input5 {0,0,0,0,0,1};
    const std::vector<int> expected5 {1,0,0,0,0,0};
    std::vector<int> actual5 {0,0,0,0,0,1};
    algorithm(actual5);
    test_case(5, input5, expected5, actual5);
    
    const std::vector<int> input6 {4,6,0,7,9,0,3,5,0,1};
    const std::vector<int> expected6 {4,6,7,9,3,5,1,0,0,0};
    std::vector<int> actual6 {4,6,0,7,9,0,3,5,0,1};
    algorithm(actual6);
    test_case(6, input6, expected6, actual6);
    
    const std::vector<int> input7 {5};
    const std::vector<int> expected7 {5};
    std::vector<int> actual7 {5};
    algorithm(actual7);
    test_case(7, input7, expected7, actual7);
    
    const std::vector<int> input8 {};
    const std::vector<int> expected8 {};
    std::vector<int> actual8 {};
    algorithm(actual8);
    test_case(8, input8, expected8, actual8);
    
}
int main() {
    move_zeros_to_the_end_test(move_zeros_to_the_end);
    return 0;
}