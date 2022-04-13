#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& numbers) {
    for (auto number: numbers)
        out << number << ' ';
    
    return out;
}

void move_even_numbers_to_the_end(std::vector<int>& numbers) {
    const int size = numbers.size();
    
    std::vector<int> evens;
    evens.reserve(size);

    int new_index = 0;
    for (int index = 0; index < size; ++index) {
        if (numbers[index] % 2 == 0) {
            evens.push_back(numbers[index]);
            continue;
        }
        numbers[new_index] = numbers[index];
        ++new_index;
    }
    const int even_size = evens.size();
    for (int index = 0; index < even_size; ++index) {
        numbers[new_index + index] = evens[index];
    }
    return;
}

void test_case(int test_number, 
               const std::vector<int>& input, 
               const std::vector<int>& expected, 
               const std::vector<int>& actual
) {
    std::cout << "Test  #" << test_number << ":\t";
    if (expected == actual) {
        std::cout << "ok\n";
    } else {
        std::cout << "FAILED\n";
        std::cout << "input   :   " << input    << '\n';
        std::cout << "expected:   " << expected << '\n';
        std::cout << "actual  :   " << actual   << '\n';
    }
    
}
void move_even_numbers_to_the_end_test(void (*algorithm)(std::vector<int>&)) {
    const std::string greetings("move_even_numbers_to_the_end");
    std::cout << greetings << ":\n";

    const std::vector<int> input1 {1, 1, 1};
    const std::vector<int> expected1 {1, 1, 1};
    std::vector<int> actual1 {1, 1, 1};
    algorithm(actual1);
    test_case(1, input1, expected1, actual1);
    
    const std::vector<int> input2 {1, 1, 2, 1};
    const std::vector<int> expected2 {1, 1, 1, 2};
    std::vector<int> actual2 {1, 1, 2, 1};
    algorithm(actual2);
    test_case(2, input2, expected2, actual2);
    
    const std::vector<int> input3 {1, 4, 1, 2, 1};
    const std::vector<int> expected3 {1, 1, 1, 4, 2};
    std::vector<int> actual3 {1, 4, 1, 2, 1};
    algorithm(actual3);
    test_case(3, input3, expected3, actual3);
    
    const std::vector<int> input4 {2, 4, 6, 8};
    const std::vector<int> expected4 {2, 4, 6, 8};
    std::vector<int> actual4 {2, 4, 6, 8};
    algorithm(actual4);
    test_case(4, input4, expected4, actual4);
    
    const std::vector<int> input5 {1, 1, 2, 4, 6, 8};
    const std::vector<int> expected5 {1, 1, 2, 4, 6, 8};
    std::vector<int> actual5 {1, 1, 2, 4, 6, 8};
    algorithm(actual5);
    test_case(5, input5, expected5, actual5);
    
    const std::vector<int> input6 {1, 1, 2, 4, 3, 5, 6, 8};
    const std::vector<int> expected6 {1, 1, 3, 5, 2, 4, 6, 8};
    std::vector<int> actual6 {1, 1, 2, 4, 3, 5, 6, 8};
    algorithm(actual6);
    test_case(6, input6, expected6, actual6);
    
    const std::vector<int> input7 {1, 1, 2, 4, 3, 5, 6, 8, 9, 1};
    const std::vector<int> expected7 {1, 1, 3, 5, 9, 1, 2, 4, 6, 8};
    std::vector<int> actual7 {1, 1, 2, 4, 3, 5, 6, 8, 9, 1};
    algorithm(actual7);
    test_case(7, input7, expected7, actual7);
}


int main() {
    move_even_numbers_to_the_end_test(move_even_numbers_to_the_end);

    return 0;
}