#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& elements) {
    for (auto element: elements)
        out << element << ' ';

    return out;
}

int get_product(const std::vector<int> &numbers) {
    if (numbers.size() < 2)
        return -1;
    
    int first  = numbers[0] > numbers[1] ? numbers[0] : numbers[1];
    int second = numbers[0] < numbers[1] ? numbers[0] : numbers[1];
    
    for (std::size_t index = 2; index < numbers.size(); ++index) {
        if (numbers[index] > second) {
        
            if (numbers[index] > first) {
                second = first;
                first  = numbers[index];
            
                continue;
            }
            second = numbers[index];
        }
    }
    
    return first * second;
}
void test_case(int test_number, int expected1, int actual1, const std::vector<int>& case1) {
   std::cout << "Test #" << test_number << ":\t";
    if (expected1 == actual1) {
        std::cout << "ok\n";
    } else {
        std::cout << "FAILED\n";
        std::cout << "input:    " << case1 << '\n';
        std::cout << "expected: " << expected1 << '\n';
        std::cout << "actual:   " << actual1 << '\n';
    } 
}
void get_product_test(int (*algorithm)(const std::vector<int>&)) {
    const std::vector<int> case1 {1, 2, 3};
    const int expected1 = 6;
    const int actual1 = algorithm(case1);
    
    test_case(1, expected1, actual1, case1);
    
    
    const std::vector<int> case2 {1, 2, 3, 1, 2};
    const int expected2 = 6;
    const int actual2 = algorithm(case2);
    
    test_case(2, expected2, actual2, case2);
    
    
    const std::vector<int> case3 {3, 3, 3, 3, 3};
    const int expected3 = 9;
    const int actual3 = algorithm(case3);
    
    test_case(3, expected3, actual3, case3);
    
    
    const std::vector<int> case4 {3, 3, 3, 3, 3, 9, 8};
    const int expected4 = 72;
    const int actual4 = algorithm(case4);
    
    test_case(4, expected4, actual4, case4);
    
    
    const std::vector<int> case5 {3, 3, 3, 3, 3, 7, 4};
    const int expected5 = 28;
    const int actual5 = algorithm(case5);
    
    test_case(5, expected5, actual5, case5);
    
    
    const std::vector<int> case6 {10, 3, 3, 3, 3, 7, 4};
    const int expected6 = 70;
    const int actual6 = algorithm(case6);
    
    test_case(6, expected6, actual6, case6);
    
    
    const std::vector<int> case7 {10, 9, 3, 3, 3, 7, 4};
    const int expected7 = 90;
    const int actual7 = algorithm(case7);
    
    test_case(7, expected7, actual7, case7);
    
    
    const std::vector<int> case8 {10, 11, 3, 3, 3, 7, 4};
    const int expected8 = 110;
    const int actual8 = algorithm(case8);
    
    test_case(8, expected8, actual8, case8);

    const std::vector<int> case9 {10, 0, 3, 12, 3, 7, 4};
    const int expected9 = 120;
    const int actual9 = algorithm(case9);
    
    test_case(9, expected9, actual9, case9);

    const std::vector<int> case10 {7, 6, 10, 3, 13, 3, 7, 4};
    const int expected10 = 130;
    const int actual10 = algorithm(case10);
    
    test_case(10, expected10, actual10, case10);
}
int main() {
    get_product_test(get_product);

    return 0;
}