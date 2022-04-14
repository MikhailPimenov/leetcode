#include <iostream>
#include <vector>

struct Numbers {
    int first;
    int second;
    
    Numbers(int firstp, int secondp) : first{firstp}, second{secondp} {}
};

bool operator==(const Numbers& left, const Numbers& right) {
    return (left.first == right.first) && (left.second == right.second);
}


std::ostream& operator<<(std::ostream& out, const Numbers& object);
std::ostream& operator<<(std::ostream& out, const std::vector<int>& numbers);
void test_case(
    int test_number, 
    const std::vector<int>& input, 
    int target,
    const Numbers& expected,
    const Numbers& actual
) {
    std::cout << "Test #" << test_number << ":\t";
    if (actual == expected) {
        std::cout << "ok\n";
    } else {
        std::cout << "FAILED\n";
        std::cout << "input:\t\t"  << input    << '\n'; 
        std::cout << "target:\t\t" << target   << '\n';
        std::cout << "expected:\t" << expected << '\n';
        std::cout << "actual:\t\t" << actual   << '\n';
    }
    
}

Numbers target_sum(const std::vector<int>& numbers, int target) {
    int left  = 0;
    int right = numbers.size() - 1;
    
    int sum = numbers[left] + numbers[right];

    while (left < right) {
        if (sum < target) {
            ++left;
            sum = numbers[left] + numbers[right];
        } else if (sum > target) {
            --right;
            sum = numbers[left] + numbers[right];
        } else {
            return Numbers(left, right);
        }
    }
    
    return Numbers(-1, -1);
}




void target_sum_test(Numbers (*algorithm)(const std::vector<int>&, int)) {
    std::cout << "target_sum\n";

    {
        const std::vector<int> input {1,5,10};
        const int target = 11;
        const Numbers expected {0, 2};
        const Numbers actual = algorithm(input, target);
        test_case(1, input, target, expected, actual);
    }
    
    {
        const std::vector<int> input {1,5,10,25,33};
        const int target = 35;
        const Numbers expected {2, 3};
        const Numbers actual = algorithm(input, target);
        test_case(2, input, target, expected, actual);
    }
    
    {
        const std::vector<int> input {1,5,10};
        const int target = 110;
        const Numbers expected {-1, -1};
        const Numbers actual = algorithm(input, target);
        test_case(3, input, target, expected, actual);
    }
    
     {
        const std::vector<int> input {1,5,10,11,12,13,15};
        const int target = 110;
        const Numbers expected {-1, -1};
        const Numbers actual = algorithm(input, target);
        test_case(4, input, target, expected, actual);
    }
    
    {
        const std::vector<int> input {3,5,10,11,12,13,15};
        const int target = 1;
        const Numbers expected {-1, -1};
        const Numbers actual = algorithm(input, target);
        test_case(5, input, target, expected, actual);
    }
    
    
}
int main() {
    target_sum_test(target_sum);

    return 0;
}

std::ostream& operator<<(std::ostream& out, const Numbers& object) {
    out << object.first << ' ' << object.second;
    return out;
}
std::ostream& operator<<(std::ostream& out, const std::vector<int>& numbers) {
    for (int number: numbers) 
        out << number << ' ';
    return out;
}